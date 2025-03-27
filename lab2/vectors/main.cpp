#include <iostream>
#include "Polynomial.h"
#include "Vecpolynomial.h"

using namespace std;

int main() {
    int n;
    set_num_elements(n);

    VectPolynomial V1(n), V2(n);
    cout << "Enter elements for V1:\n";
    V1.set_vector();
    cout << "Enter elements for V2:\n";
    V2.set_vector();

    VectPolynomial V3 = V3.operate_vectors(V1, V2,'+');

    cout << "Resulting vector Vout:\n";
    V3.print_vector();

    double x;
    cout << "Enter value of x for evaluation: ";
    cin >> x;
    V3.evaluate_and_print(x);

    return 0;
}

// g++ main.cpp Product.cpp Warehouse.cpp -o main
// ./main.exe