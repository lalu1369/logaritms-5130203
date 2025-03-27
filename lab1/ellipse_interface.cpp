#include <iostream>
#include <cstdio>
#include "ellipse.h"

#define MARGIN    0.5
#define PRECISION 0.1

void run_ellipse_interface() {
    
    Ellipse e(0, 0, 2.5, 1.5);
    e.set_axis('Y');
    char a = e.get_axis();
    std::cout << "Printing:" << std::endl;
    e.print();
    std::cout << std::endl;

    std::cout << "Extra:" << std::endl;
    std::cout << " a: " << e.get_a() << std::endl;
    std::cout << " b: " << e.get_b() << std::endl;
    std::cout << " c: " << e.get_c() << std::endl;
    std::cout << "LR: " << e.get_lr() << std::endl;
    std::cout << " e: " << e.get_e() << std::endl;
    std::cout << "~P: " << e.approximate_perimeter() << std::endl;
    std::cout << " S: " << e.get_area() << std::endl;

    std::cout << "(2.5,   ?) => (2.5, " << e.find_y_for_known_x(2.5) << ")" << std::endl;
    std::cout << "(  ?, 1.5) => (" << e.find_x_for_known_y(1.5) << ", 1.5)" << std::endl;
    std::cout << std::endl;

    renderEllipse(e, a, MARGIN, PRECISION);
}