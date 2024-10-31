#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "matrix.h"

using namespace std;

int main(){
    Matrix A;
    Matrix AT;
    A.set(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0);
    A.print();
    cout << endl;
    A.print();
    A.transpose();
    //double Elem= A.getElem(2,2);
    A.save("matrixA.txt");
    AT.load("matrixA.txt");
    AT.print();
    cout << endl;
    return 0;
}