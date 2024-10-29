#include <iostream>
#include <iomanip>
#include "matrix.h"

using namespace std;

int main(){
    Matrix A;
    A.set(1.2246,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0);
    A.print();
    cout << "\n";
    A.set(2,2,4.041);
    A.print();
    //double Elem= A.getElem(2,2);
    cout << endl;
    A.transpose();
    A.print();
    return 0;
}