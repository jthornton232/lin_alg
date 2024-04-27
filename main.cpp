#include <iostream>
#include "matrix.h"

int main() {

    Matrix<int> A(3,3);
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            A.setElement(i,j,i*j);
        }
    }
    Matrix<int> B = Matrix(A);
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            std::cout << B.getElement(i,j) << " " << std::flush;
        }
        std::cout << std::endl;
    }

    return 0;
}