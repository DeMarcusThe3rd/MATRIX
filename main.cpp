#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "matrix.h"

using namespace std;

int main(){
Matrix A, B;
    A.set(2.0, -5.0, 3.0, 1.0, 7.0, -2.0, -1.0, 4.0, 1.0);
    B.set(7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0);
    
    // Test print function for A and B
    cout << "Matrix A:" << endl;
    A.print();
    cout << "Matrix B:" << endl;
    B.print();

    // Test setting individual elements
    cout << "Setting element (0, 0) in Matrix A to 10.0:" << endl;
    A.set(0, 0, 10.0);
    A.print();

    // Test getting an element
    cout << "Element at (1, 1) in Matrix B: ";
    B.getElem(1, 1);
    cout << endl;

    // Test transpose of Matrix A
    cout << "Transpose of Matrix A:" << endl;
    A.transpose();
    A.print();

    // Test setting Matrix A to identity matrix
    cout << "Setting Matrix A to identity matrix:" << endl;
    A.eye();
    A.print();

    // Test setting Matrix A to zero matrix
    cout << "Setting Matrix A to zero matrix:" << endl;
    A.zero();
    A.print();

    // Re-set A and B for further operations
    A.set(2.0, -5.0, 3.0, 1.0, 7.0, -2.0, -1.0, 4.0, 1.0);
    B.set(7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0);

    // Test saving Matrix A to file
    cout << "Saving Matrix A to 'matrixA.txt':" << endl;
    A.save("matrixA.txt");
    A.zero();

    // Test loading Matrix A from file
    cout << "Loading Matrix A from 'matrixA.txt':" << endl;
    A.zero(); // Reset A to check load functionality
    A.load("matrixA.txt");
    A.print();

    // Test addition of A and B
    cout << "Matrix A + Matrix B:" << endl;
    A.add(B);
    A.print();

    // Reset A and B for subtraction test
    A.set(2.0, -5.0, 3.0, 1.0, 7.0, -2.0, -1.0, 4.0, 1.0);
    cout << "Matrix A - Matrix B:" << endl;
    A.sub(B);
    A.print();

    // Test row-column multiplication of A and B
    cout << "Dot product of row 0 of Matrix A and column 0 of Matrix B:" << endl;
    double result = A.rcMult(B, 0, 0);
    cout << "Result: " << result << endl;

    // Reset A and B for matrix multiplication tests
    A.set(2.0, -5.0, 3.0, 1.0, 7.0, -2.0, -1.0, 4.0, 1.0);

    // Test left multiplication of B by A
    cout << "Left multiplication of B by A (B = A * B):" << endl;
    B.lMult(A);
    B.print();

    // Reset A and B for right multiplication test
    B.set(7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0);
    cout << "Right multiplication of A by B (A = A * B):" << endl;
    A.rMult(B);
    A.print();

    // Test scalar multiplication
    cout << "Scalar multiplication of Matrix A by 0.5:" << endl;
    A.sMult(0.5);
    A.print();

    // Test determinant calculation
    cout << "Determinant of Matrix A:" << endl;
    double detA = A.det();
    cout << "Determinant: " << detA << endl;

    // Test inverse calculation
    cout << "Inverse of Matrix A (if exists):" << endl;
    A.inv();
    A.print();

    return 0;
}