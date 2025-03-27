#pragma once


class polynomial {

public:
    double coefs,expos;

public:
    polynomial(double coefs = 0.0, double expos = 0.0);
    polynomial(const polynomial& p);
    ~polynomial();
    
    void set_coefficients(double coefs);
    void set_exponents(double expos);
    double get_coefficients();
    double get_exponents();

    void print();
    double evaluate(double x);

    polynomial operator + (const polynomial & p);
    polynomial operator - (const polynomial & p);
};