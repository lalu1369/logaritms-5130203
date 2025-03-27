#include <iostream>
#include <cmath>
#include "Vecpolynomial.h"

using namespace std;

void set_num_elements(int& n) {
    do {
        cout << "Input #elements: ";
        cin >> n;
    } while (n <= 0);
}

VectPolynomial::VectPolynomial(){
    this->size = 0;
    this->vec = nullptr;
}

VectPolynomial::VectPolynomial(int n){
    this->size = n;
    this->vec = new polynomial[n];
}
VectPolynomial::VectPolynomial(const VectPolynomial& p){
    this->size = p.size;
    this->vec = new polynomial[p.size];

    for (int i = 0; i < p.size; i++) {
        this->vec[i] = p.vec[i];
    }
}
VectPolynomial::~VectPolynomial(){
    delete[] this->vec;
}

void VectPolynomial::set_size(int n){
    if (this->vec != nullptr) {
        delete[] this->vec;
    }

    this->size = n;
    this->vec = new polynomial[n];
}

int VectPolynomial::get_size(){
    return this->size;
}
int VectPolynomial::find_degree() {
    int max = 0;

    for (int i = 0; i < this->size; i++) {
        int expo = this->vec[i].get_exponents();  

        if (expo > max) {  
            max = expo;
        }
    }
    return max; 
}


void VectPolynomial::set_vector(){
    double coef, expos;

    for (int i = 0; i < this->get_size(); i++) {
        cout << "Element " << i + 1 << ":" << endl;
        cout << "Coefficients: "; 
        cin  >> coef;
        cout << "Exponents: "; 
        cin  >> expos;
        this->vec[i] = polynomial(coef, expos);
    }
}
void VectPolynomial::print_vector(){
    for (int i = 0; i < this->get_size(); i++) {
        cout << "[" << i + 1 << "]: ";
        this->vec[i].print();
    }
}

void VectPolynomial::evaluate_and_print(double x) {
    for (int i = 0; i < this->size; i++) {
        cout << "Polynomial " << i + 1 << ": ";
        this->vec[i].print();
        cout << "Evaluated at x = " << x << " : " << this->vec[i].evaluate(x) << endl;
    }
}

VectPolynomial VectPolynomial::operate_vectors(VectPolynomial& V1, VectPolynomial& V2, char op) {
    int n = V1.get_size();
    VectPolynomial Vout(n);  

    for (int i = 0; i < n; i++) {
        if (op == '+') {
            if (i % 2 == 0) {
                
                Vout.vec[i] = V1.vec[i] + V2.vec[i + 1];
            }
            else {
                
                Vout.vec[i] = V1.vec[i] + V2.vec[i - 1];
            }
        }
        else if (op == '-') {
            if (i % 2 == 0) {
                
                Vout.vec[i] = V1.vec[i] - V2.vec[i + 1];
            }
            else {
                
                Vout.vec[i] = V1.vec[i] - V2.vec[i - 1];
            }
        }
    }

    return Vout;
}

