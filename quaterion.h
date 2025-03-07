#pragma once

class quaterion {

private:
	double a;
	double b;
	double c;
	double d;


public://1
	quaterion(double a = 1, 
		      double b = 0, 
			  double c = 0, 
			  double d = 0);

	quaterion(const quaterion& q);
	~quaterion();

public://2
	void set_quaterion(double a, 
		               double b,  
					   double c,  
					   double d);

public://3
	void get_quaterion(double& a, 
		               double& b, 
					   double& c, 
					   double& d);

public://4
	void print_quanterion();

public://5
	double quaterion_rate();

public://6
	quaterion conjugate();

public://7
	quaterion norm();

public://8
	quaterion inversion();
};

	quaterion add (quaterion x, quaterion y);
	quaterion sub (quaterion x, quaterion y);
	quaterion mul (quaterion x, quaterion y);
	quaterion div (quaterion x, quaterion y);

	double dotproduct     (quaterion x, quaterion y);
	double eucl_distance  (quaterion x, quaterion y);
	double Chebyshev_norm (quaterion x, quaterion y);
