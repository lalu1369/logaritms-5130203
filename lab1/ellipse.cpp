#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include "ellipse.h"

Ellipse::Ellipse(double h, double k, double a, double b) {
    this->a = a;
    this->b = b;
    this->h = h;
    this->k = k;
}

Ellipse::~Ellipse() {}

double Ellipse::get_c(void) const
{
    return sqrt(a * a - b * b);
}

double Ellipse::get_v1(void) const
{
    switch (axis) {

    case 'X':

        return h - a;
        break;
    case 'Y':

        return k - a;
        break;
    default:

        std::cerr << "Error axis of main axis was not stated";
    }
}

double Ellipse::get_v2(void) const
{
    switch (axis) {

    case 'X':

        return h + a;
        break;
    case 'Y':

        return k + a;
        break;
    default:

        std::cerr << "Error axis of main axis was not stated";
    }
}

double Ellipse::get_f1(void) const
{
    switch (axis) {

    case 'X':

        return h - get_c();
        break;
    case 'Y':

        return k - get_c();
        break;

    default:
        std::cerr << "Error axis of main axis was not stated";
    }
}

double Ellipse::get_f2(void) const
{
    switch (axis) {

    case 'X':

        return h + get_c();
        break;

    case 'Y':

        return k + get_c();
        break;

    default:
        std::cerr << "Error axis of main axis was not stated";
    }
}

double Ellipse::get_lr(void) const
{
    return 2 * (b * b) / a;
}

double Ellipse::get_e(void) const
{
    return get_c() / a;
}

void Ellipse::set_axis(char axis)
{

    this-> axis = toupper(axis);
    
}

void Ellipse::set_h(double h)
{
    this->h = h;
}

void Ellipse::set_k(double k)
{
    this->k = k;
}

void Ellipse::set_a(double a)
{
    if (a <= b)
        throw std::invalid_argument("значение большой полуоси a должно быть больше значения малой полуоси b");

    this->a = a;
}

void Ellipse::set_b(double b)
{
    if (a <= b)
        throw std::invalid_argument("значение большой полуоси a должно быть больше значения малой полуоси b");

    this->b = b;
}
 
char Ellipse::get_axis() const 
{
    return axis;
}

double Ellipse::get_h(void) const
{
    return h;
}

double Ellipse::get_k(void) const
{
    return k;
}

double Ellipse::get_a(void) const
{
    return a;
}

double Ellipse::get_b(void) const
{
    return b;
}

void Ellipse::print() const
{
    switch (axis) {
    case 'X': // Major axis on the x-axis
        printf("(x - %.2f)^2/%.2f^2 + (y - %.2f)^2/%.2f^2 = 1\n", h, a, k, b);
        printf("  C: (%+.2f, %+.2f)\n", h, k);
        printf("V_1: (%+.2f, %+.2f)\n", get_v1(), k);
        printf("V_2: (%+.2f, %+.2f)\n", get_v2(), k);
        printf("F_1: (%+.2f, %+.2f)\n", get_f1(), k);
        printf("F_2: (%+.2f, %+.2f)\n", get_f2(), k);
        break;

    case 'Y': // Major axis on the y-axis
        printf("(x - %.2f)^2/%.2f^2 + (y - %.2f)^2/%.2f^2 = 1\n", h, b, k, a);
        printf("  C: (%+.2f, %+.2f)\n", h, k);
        printf("V_1: (%+.2f, %+.2f)\n", h, get_v1());
        printf("V_2: (%+.2f, %+.2f)\n", h, get_v2());
        printf("F_1: (%+.2f, %+.2f)\n", h, get_f1());
        printf("F_2: (%+.2f, %+.2f)\n", h, get_f2());
        break;

    default: // Invalid axis
        fprintf(stderr, "Error: Invalid axis specified. Use 'x' or 'y'.\n");
        break;
    }
}

bool Ellipse::intersects(double x, double y) const
{
    switch (axis) {
    case 'X':
        return (x - h) * (x - h) / (a * a) + (y - k) * (y - k) / (b * b) < 1;
        break;
    case 'Y':
        return (x - h) * (x - h) / (b * b) + (y - k) * (y - k) / (a * a) < 1;
        break;
    default:
        std::cerr << "Error axis of main axis was not stated";
    }

}

double Ellipse::approximate_perimeter(void) const
{
    return M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
}

double Ellipse::get_area(void) const
{
    return M_PI * a * b;
}

// дано: x, h, k, a, b
// найти: y
// (x - h)*(x - h)/(a*a) + (y - k)*(y - k)/(b*b) == 1
// (1)y*y + (-2*k)*y + (k*k - (1 - (x - h)*(x - h)/(a*a))*(b*b)) == 0
//
// y^2 + by + c == 0
// a = 1
// b = -2*k
// c = k*k - (1 - (x - h)*(x - h)/(a*a))*(b*b)
// D = b^2 - 4ac
// y = (-b +/- sqrt (D))/2a
// y = (2k +/- sqrt (4k^2 - 4c))/2
double Ellipse::find_y_for_known_x(double x) const
{
    double c = k * k - (1 - (x - h) * (x - h) / (a * a)) * (b * b);
    double D = 4 * k * k - 4 * c;
    double y_0 = (2 * k + sqrt(D)) / 2;
    double y_1 = (2 * k - sqrt(D)) / 2;

    (void)y_1;
    return y_0;
}

// аналогично
double Ellipse::find_x_for_known_y(double y) const
{
    double c = h * h - (1 - (y - k) * (y - k) / (b * b)) * (a * a);
    double D = 4 * h * h - 4 * c;
    double x_0 = (2 * h + sqrt(D)) / 2;
    double x_1 = (2 * h - sqrt(D)) / 2;

    (void)x_1;
    return x_0;
}
void renderEllipse(const Ellipse& e, char axis, double MARGIN = 2.0, double PRECISION = 0.1) {
    std::cout << "Rendering:" << std::endl;

    switch (axis) {
    case 'X': // Major axis on the x-axis
        for (double y = -e.get_b() - MARGIN; y <= e.get_b() + MARGIN; y += PRECISION) {
            for (double x = -e.get_a() - MARGIN; x <= e.get_a() + MARGIN; x += PRECISION) {
                std::cout << (e.intersects(x, y) ? "##" : "..");
            }
            std::cout << std::endl;
        }
        break;

    case 'Y': // Major axis on the y-axis
        for (double y = -e.get_a() - MARGIN; y <= e.get_a() + MARGIN; y += PRECISION) {
            for (double x = -e.get_b() - MARGIN; x <= e.get_b() + MARGIN; x += PRECISION) {
                std::cout << (e.intersects(x, y) ? "##" : "..");
            }
            std::cout << std::endl;
        }
        break;

    default: // Invalid axis
        std::cerr << "Error: Invalid axis specified. Use 'x' or 'y'." << std::endl;
        break;
    }
}