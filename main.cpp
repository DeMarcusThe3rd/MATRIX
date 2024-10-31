#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "matrix.h"

using namespace std;

int main(){
    Matrix A;
    Matrix B;
    A.set(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0);
    B.set(7.0,8.0,9.0,10.0,11.0,12.0,13.0,14.0,15.0);
    //double result = A.rcMult(B,0,0);
    A.sMult(4);
    A.print();
    return 0;
}