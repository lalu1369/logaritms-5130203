#pragma once
#include "Polynomial.h"

class VectPolynomial{

public:
    polynomial* vec;
    int size;
    int degree;

public:
    VectPolynomial();
    VectPolynomial(int n);
    VectPolynomial(const VectPolynomial& p);
    ~VectPolynomial();
    int find_degree();
    void set_size(int n);
    int get_size();
    void set_vector();
    void print_vector();
    void evaluate_and_print(double x);
    VectPolynomial operate_vectors(VectPolynomial& V1, VectPolynomial& V2,char opr);
};

void set_num_elements(int& n);