#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "matrix.h"

using namespace std;

void Matrix::print(){
    for (int m =0;m<3;m++){ 
        for (int n=0;n<3;n++){
            cout << "[" << setw(7) << fixed << setprecision(3) << x[m][n] << "]";
            cout << "  ";
        }
        cout << endl;
    }
    cout << endl; 
}

void Matrix::set(double a,double b,double c,double d,double e,double f,double g,double h,double i){ //set all elements of the matrix 
    double values[9] = {a,b,c,d,e,f,g,h,i};
    int index =0;

    for (int m =0;m<3;m++){
        for (int n=0;n<3;n++){
            x[m][n] = values[index++];
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
    for (int m=0;m<3;m++){
        for (int n=m;n<3;n++){
            double temp = x[m][n];
            x[m][n] = x[n][m];
            x[n][m] = temp;
        }
    }   
}

void Matrix::eye(){
    for (int m=0;m<3;m++){
        for(int n=0;n<3;n++){
            if (m==n){
                x[m][n] = 1.0;
            }
            else{
                x[m][n] = 0.0;
            }
        }
    }
}

void Matrix::zero(){
    for (int m=0;m<3;m++){
        for(int n=0;n<3;n++){
            x[m][n] = 0.0;
        }
    }
}

void Matrix::save(string filename){
    ofstream savef(filename);

    if(savef.is_open()){
        for (int m =0;m<3;m++){ 
                for (int n=0;n<3;n++){
                    savef << x[m][n] << " ";
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
        for (int m = 0; m < 3; ++m) {
            for (int n = 0; n < 3; ++n) {
                loadf >> x[m][n];
            }
        }
    }
    else{
        cout << "Error opening file." << endl;
    }
    loadf.close();
}

void Matrix::add(Matrix B){
     for (int m =0;m<3;m++){ 
        for (int n=0;n<3;n++){
            x[m][n]+= B.x[m][n];
        }
    }
}

void Matrix::sub(Matrix B){
for (int m =0;m<3;m++){ 
        for (int n=0;n<3;n++){
            x[m][n]-= B.x[m][n];
        }
    }
}

