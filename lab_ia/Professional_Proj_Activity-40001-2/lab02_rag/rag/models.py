import requests

OLLAMA_URL = "http://localhost:11434"

class Models():
    def get_models(self) -> list:
        thelist = requests.get(OLLAMA_URL+"/api/tags")
        jsondata = thelist.json()
        result = list()

        for model in jsondata["models"]:
            result.append(model["model"])

        return result