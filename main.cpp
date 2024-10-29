#include <iostream>
#include <iomanip>
#include "matrix.h"
#include <vector>

using namespace std;

int main(){
    Matrix matrix;
    matrix.set(1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0);
    matrix.print();


    return 0;
}