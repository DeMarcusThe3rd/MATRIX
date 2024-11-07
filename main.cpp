#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "matrix.h"

using namespace std;

int main(){
Matrix A, B;
    A.print();
    A.set(2.0, -5.0, 3.0, 1.0, 7.0, -2.0, -1.0, 4.0, 1.0);
    B.set(7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0);
    
    // Test print function for A and B
    cout << "Matrix A:" << endl;
    A.print();
    cout << "Matrix B:" << endl;
    B.print();

    // Test setting individual elements
    cout << "Setting element (0, 0) in Matrix B to 1.0:" << endl;
    //B.set(0, 0, 1.0);
    //B.print();

    // Test getting an element
    cout << "Element at (1, 1) in Matrix B: ";
    B.getElem(1, 1);
    cout << endl;

    // Test transpose of Matrix B
    cout << "Transpose of Matrix B:" << endl;
    B.transpose();
    B.print();

    // Test setting Matrix A to identity matrix
    cout << "Setting Matrix A to identity matrix:" << endl;
    A.eye();
    A.print();

    // Test setting Matrix A to zero matrix
    cout << "Setting Matrix A to zero matrix:" << endl;
    A.zero();
    A.print();

    // Re-set A and B for further operations
    A.set(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    B.set(7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0);

    // Test saving Matrix A to file
    B.save("matrixB.txt");
    B.zero();

    // Test loading Matrix A from file
    B.load("notValid.txt");
    B.print();

    // Test addition of A and B
    cout << "Matrix A + Matrix B:" << endl;
    A.add(B);
    A.print();

    // Reset A and B for subtraction test
    A.set(2.0, -5.0, 3.0, 1.0, 7.0, -2.0, -1.0, 4.0, 1.0);
    cout << "Matrix A - Matrix B:" << endl;
    A.sub(B);
    A.print();

    A.set(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    B.set(7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0);
    // Test row-column multiplication of A and B
    cout << "Dot product of row 0 of Matrix A and column 0 of Matrix B:" << endl;
    double result = A.rcMult(B, 0, 0);
    cout << "Result: " << result << endl;

    // Reset A and B for matrix multiplication tests
    A.set(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    B.set(7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0);
    // Test left multiplication of B by A
    cout << "Left multiplication of B by A (B = A * B):" << endl;
    A.lMult(B);
    A.print();

    // Reset A and B for right multiplication test
    A.set(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    B.set(7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0);
    cout << "Right multiplication of A by B (A = A * B):" << endl;
    A.rMult(B);
    A.print();

    // Test scalar multiplication
    A.set(1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0);
    B.set(-1.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0);
    cout << "Scalar multiplication of Matrix A by 0.5:" << endl;
    A.sMult(0.5);
    A.print();

    // Test determinant calculation
    cout << "Determinant of Matrix A:" << endl;
    double detA = A.det();
    cout << "Determinant: " << detA << endl;

    // Test inverse calculation
    cout << "Inverse of Matrix A (if exists):" << endl;
    A.print();
    A.inv();
    A.print();

    return 0;
}