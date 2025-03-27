#include <iostream>
#include <cmath>
#include <algorithm>
#include "quaterion.h"

void run_quaternion_interface() {
    std::cout << "****************Quaterion1****************\n";
    quaterion q(1, 2, 3, 4);
    q.print_quanterion();

    std::cout << "****************Rate1****************\n";
    double rate = q.quaterion_rate();
    std::cout << "Rate: " << rate << '\n';

    std::cout << "****************Quaterion1conjugate****************\n";
    q.conjugate().print_quanterion();

    std::cout << "****************Quaterion1norm****************\n";
    q.norm().print_quanterion();

    std::cout << "****************Quaterion1inversion****************\n";
    q.inversion().print_quanterion();

    std::cout << "****************Quaterion2****************\n";
    quaterion q2(5, 6, 7, 8);
    q2.print_quanterion();
    double rate2 = q2.quaterion_rate();

    std::cout << "****************Rate2****************\n";
    std::cout << "Rate: " << rate2 << '\n';

    std::cout << "****************Quaterion2conjugate****************\n";
    q2.conjugate().print_quanterion();

    std::cout << "****************Quaterion2norm****************\n";
    q2.norm().print_quanterion();

    std::cout << "****************Quaterion2inversion****************\n";
    q2.inversion().print_quanterion();

    quaterion q3;

    std::cout << "****************Addtion****************\n";
    q3 = add(q, q2);
    q3.print_quanterion();

    std::cout << "**************Subtraction**************\n";
    q3 = sub(q2, q);
    q3.print_quanterion();

    std::cout << "************Multipilcation*************\n";
    q3 = mul(q, q2);
    q3.print_quanterion();

    std::cout << "***************Division****************\n";
    q3 = div(q, q2);
    q3.print_quanterion();

    std::cout << "***************DotProduct**************\n";
    double d = dotproduct(q, q2);
    std::cout << "The dot product of quaterions q and q2 is: " << d << '\n\n';

    std::cout << "***********EuclideanDistance***********\n";
    double e = eucl_distance(q, q2);
    std::cout << "The Euclidean distance of quaterions q and q2 is: " << e << '\n\n';

    std::cout << "***************ChebyshevNorm**************\n";
    double c = Chebyshev_norm(q2, q);
    std::cout << "The dot product of Chebyshev Norm q and q2 is: " << c << '\n\n';

    std::cout << "***************************************\n";
}