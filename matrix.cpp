#include <iostream>
#include <iomanip>
#include "matrix.h"
#include <vector>

using namespace std;

void Matrix::print(){
    int row;
    int col;

    for (row =0;row<3;row++){
        for (col=0;col<3;col++){
            cout << x[row][col] <<endl;
        }
    }
}

void Matrix::set(double a,double b,double c,double d,double e,double f,double g,double h,double i){ //set all elements of the matrix 
    double values[9] = {a,b,c,d,e,f,g,h,i};
    int index =0;
    int row;
    int col;

    for (row =0;row<3;row++){
        for (col=0;col<3;col++){
            x[row][col] = values[index++];
        }
    }
}

void Matrix::set(int m, int n, double elem){ //set one specific element of the matrix 
    if ((m>0 && m<3) &&(n>0 && n<3)){
        x[m][n] = elem;
    }
    else{
        cout << "Matrix is 3x3, Index out of Bounds" <<endl;
    }
}

double Matrix::getElem(int m, int n){
    return 0;
}