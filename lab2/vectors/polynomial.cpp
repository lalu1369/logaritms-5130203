#include <iostream>
#include <cmath>
#include "Polynomial.h"

using namespace std;


polynomial::polynomial(double coefs, double expos) {
    this->coefs = coefs;
    this->expos = expos;
}

polynomial::polynomial(const polynomial& p) {
    this->coefs = p.coefs;
    this->expos = p.expos;
}

polynomial::~polynomial(){}

void polynomial::set_coefficients(double coefs){
    this->coefs = coefs;
}

void polynomial::set_exponents(double expos){
    this->expos = expos;
}

double polynomial::get_coefficients(){
    return this->coefs;
}

double polynomial::get_exponents(){
    return this->expos;
}

void polynomial::print() {
    cout << this->coefs << "x^" << this->expos  << endl;
}

double polynomial::evaluate(double x) {
    return this->coefs * pow(x, this->expos);
}

polynomial polynomial::operator+(const polynomial& p) {
    return polynomial(this->coefs + p.coefs, this->expos);
}

polynomial polynomial::operator-(const polynomial& p) {
    return polynomial(this->coefs - p.coefs, this->expos);
}
