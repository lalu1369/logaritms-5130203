
#pragma once 

class Ellipse {
private:
    double h, k, a, b;
    char axis;

public: //2
    Ellipse(double h = 0.0, double k = 0.0, double a = 0, double b = 0);
    Ellipse(const Ellipse& e) ;
    ~Ellipse();
    
public://3 
    double get_c() const;

public://4 
    double get_v1() const;
    double get_v2() const;
    double get_f1() const;
    double get_f2() const;

public: //5
    double get_lr() const;
    double get_e() const;

public: //6   
    void set_h(double);
    void set_k(double);
    void set_a(double);
    void set_b(double);
    void set_axis(char axis);
    double get_h() const;
    double get_k() const;
    double get_a() const;
    double get_b() const;
    char get_axis() const;

public: // 7  
    void print() const;

public: // 8
    bool intersects(double x, double y) const;

public: // 9
    double approximate_perimeter() const;

public: // 10 
    double get_area() const;

public: //11
    double find_y_for_known_x(double) const;
    double find_x_for_known_y(double) const;
};
void renderEllipse(const Ellipse& e, char axis, double MARGIN, double PRECISION);

