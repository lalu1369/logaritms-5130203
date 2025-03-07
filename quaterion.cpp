
#include <iostream>
#include <cmath>
#include <algorithm>
#include "quaterion.h"

using namespace std;


quaterion::quaterion( double a, double b, double c, double d) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

quaterion::quaterion(const quaterion& q) {
	this->a = q.a;
	this->b = q.b;
	this->c = q.c;
	this->d = q.d;
}

quaterion::~quaterion(){}

void quaterion::set_quaterion(double a, double b, double c, double d) {
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

void quaterion::get_quaterion(double& a, double& b, double& c, double& d) {
	a = this->a;
	b = this->b;
    c = this->c;
	d = this->d;

}

void quaterion::print_quanterion(){
	std::cout << "a = " << this->a << '\n';
	std::cout << "b = " << this->b << '\n';
	std::cout << "c = " << this->c << '\n';
	std::cout << "d = " << this->d << '\n';
}

double quaterion::quaterion_rate() {

	return sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2));
}

quaterion quaterion::conjugate() {
	double a, b, c, d;
	a =this->a * 1;
	b = this->b * (-1);
	c = this->c * (-1);
	d = this->d * (-1);

	return quaterion(a, b, c, d);

}

quaterion quaterion::norm() {
	double a, b, c, d;
	a = this->a / quaterion_rate();
	b = this->b / quaterion_rate();
	c = this->c / quaterion_rate();
	d = this->d / quaterion_rate();

	return quaterion (a, b, c, d);
	
}

quaterion quaterion::inversion() {
	
	double a, b, c, d;
	a = this->a / quaterion_rate();
	b = (-1 * this->b) / quaterion_rate();
	c = (-1 * this->c) / quaterion_rate();
	d = (-1 * this->d) / quaterion_rate();

	return quaterion(a, b, c, d);

}

quaterion add(quaterion x, quaterion y) {
	double a, b, c, d;
	double a1, b1, c1, d1;
	double a2, b2, c2, d2;
	x.get_quaterion(a1, b1, c1, d1);
	y.get_quaterion(a2, b2, c2, d2);
	a = a1 + a2;
	b = b1 + b2;
	c = c1 + c2;
	d = d1 + d2;

	return quaterion(a, b, c, d);
 
}

quaterion sub(quaterion x, quaterion y) {
	double a, b, c, d;
	double a1, b1, c1, d1;
	double a2, b2, c2, d2;
	x.get_quaterion(a1, b1, c1, d1);
	y.get_quaterion(a2, b2, c2, d2);
	a = a1 - a2;
	b = b1 - b2;
	c = c1 - c2;
	d = d1 - d2;

	return quaterion(a, b, c, d);

}

quaterion mul(quaterion x, quaterion y) {
	double a, b, c, d;
	double a1, b1, c1, d1;
	double a2, b2, c2, d2;
	x.get_quaterion(a1, b1, c1, d1);
	y.get_quaterion(a2, b2, c2, d2);
	a = a1 * a2;
	b = b1 * b2;
	c = c1 * c2;
	d = d1 * d2;

	return quaterion(a, b, c, d);

}

quaterion div(quaterion x, quaterion y) {
	double a, b, c, d;
	double a1, b1, c1, d1;
	double a2, b2, c2, d2;
	x.get_quaterion(a1, b1, c1, d1);
	y.get_quaterion(a2, b2, c2, d2);
	a = a1 / a2;
	b = b1 / b2;
	c = c1 / c2;
	d = d1 / d2;

	return quaterion(a, b, c, d);
}

double dotproduct(quaterion x, quaterion y) {
	double a, b, c, d;
	double a1, b1, c1, d1;
	double a2, b2, c2, d2;
	x.get_quaterion(a1, b1, c1, d1);
	y.get_quaterion(a2, b2, c2, d2);

	return a1 * a2 + b1 * b2 + c1 * c2 + d1 * d2;

}

double eucl_distance(quaterion x, quaterion y) {
	double a, b, c, d;
	double a1, b1, c1, d1;
	double a2, b2, c2, d2;
	x.get_quaterion(a1, b1, c1, d1);
	y.get_quaterion(a2, b2, c2, d2);

	return sqrt(pow((a1-a2),2)+ pow((b1 - b2), 2)+ pow((c1 - c2), 2)+ pow((d1 - d2), 2));
}

double Chebyshev_norm(quaterion x, quaterion y) {
	quaterion q;
	double a, b, c, d;
	double a1, b1, c1, d1;
	double a2, b2, c2, d2;
	x.get_quaterion(a1, b1, c1, d1);
	y.get_quaterion(a2, b2, c2, d2);
	q = sub( x, y);
	q.get_quaterion(a, b, c, d);
	 return max({ a, b, c, d });;
}