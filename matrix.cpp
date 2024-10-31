#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "matrix.h"

using namespace std;

void Matrix::print(){
    for (int row =0;row<3;row++){ 
        for (int col=0;col<3;col++){
            cout << "[" << fixed << setprecision(3) << x[row][col] << "]";
            cout << "  ";
        }
        cout << endl;
    }
}

void Matrix::set(double a,double b,double c,double d,double e,double f,double g,double h,double i){ //set all elements of the matrix 
    double values[9] = {a,b,c,d,e,f,g,h,i};
    int index =0;

    for (int row =0;row<3;row++){
        for (int col=0;col<3;col++){
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
    cout << x[m][n];
    return x[m][n];
}

void Matrix::transpose(){
    for (int row=0;row<3;row++){
        for (int col=row;col<3;col++){
            double temp = x[row][col];
            x[row][col] = x[col][row];
            x[col][row] = temp;
        }
    }   
}

void Matrix::eye(){
    for (int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if (row==col){
                x[row][col] = 1.0;
            }
            else{
                x[row][col] = 0.0;
            }
        }
    }
}

void Matrix::zero(){
    for (int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            x[row][col] = 0.0;
        }
    }
}

void Matrix::save(string filename){
    ofstream savef(filename);

    if(savef.is_open()){
        for (int row =0;row<3;row++){ 
                for (int col=0;col<3;col++){
                    savef << x[row][col] << " ";
                }
                savef << endl;
            }
        }
    else{
        cout <<"Error writing to file." <<endl;
    }
    savef.close();
}


void Matrix::load(string filename){
    ifstream loadf(filename);
    
    if(loadf.is_open()){
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                loadf >> x[row][col];
            }
        }
    }
    else{
        cout << "Error opening file." << endl;
    }
    loadf.close();
}