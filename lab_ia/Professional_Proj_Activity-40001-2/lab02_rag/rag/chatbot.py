from langchain_ollama import ChatOllama
from langchain_core.prompts import PromptTemplate
from langchain.chains import RetrievalQA
import time


class ChatBot:
    def __init__(self, vector_db, model):
        self.db = vector_db
        self.model = model
        self.llm = ChatOllama(
            model = self.model,
            base_url = "http://localhost:11434",
            temperature = 0.3
        )
        
        self.prompt_template = """
            You are an AI assistant tasked with answering questions based solely
            on the provided context. Your goal is to generate a comprehensive answer
            for the given question using only the information available in the context.

            context: {context}
            question: {question}

            <response> Your answer in Markdown format. </response>
        """

        self.chain = self.build_chain()
    
    def build_chain(self):
        prompt = PromptTemplate(template = self.prompt_template, 
                                input_variables = ["context", "question"])
        retriever = self.db.as_retriever(search_kwargs = {"k": 5})

        chain = RetrievalQA.from_chain_type(
            llm = self.llm,
            chain_type = "stuff",
            retriever = retriever,
            return_source_documents = True,
            chain_type_kwargs = {"prompt": prompt},
            verbose = True
        )

        return chain

    def qa(self, question):
        start = time.time()
        response = self.chain(question) # ASKING AI
        end = time.time()
        print(end - start) # TIME in seconds
        return { 'result' : response["result"], 'time' : (end - start) }
    