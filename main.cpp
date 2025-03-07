#include <iostream>
#include "ellipse.h"
#include "quaterion.h"

void run_ellipse_interface();
void run_quaternion_interface();

int main() {
    int opt = 0;

    std::cout << "1) Ellipse" << std::endl;
    std::cout << "2) Quaternion" << std::endl;
    std::cout << "Introduce the option: ";
    std::cin >> opt;

    switch (opt) {
        case 1:
            run_ellipse_interface();
            break;

        case 2:
            run_quaternion_interface();
            break;

        default:
            std::cout << "Invalid option!" << std::endl;
            break;
    }
    system("pause");

    return 0;
}