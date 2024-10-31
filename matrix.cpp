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
     for (int m=0;m<3;m++){ 
        for (int n=0;n<3;n++){
            x[m][n]+= B.x[m][n];
        }
    }
}

void Matrix::sub(Matrix B){
    for (int m=0;m<3;m++){ 
        for (int n=0;n<3;n++){
            x[m][n]-= B.x[m][n];
        }
    }
}

double Matrix::rcMult(Matrix B,int row, int col){
    double result = 0.0;
    for(int i=0;i<3;i++){
        result += (x[row][i])*(B.x[i][col]);
    }
    cout << "Dot Product: " << result << endl;
    return result;
}

void Matrix::lMult(Matrix B){
    double temp[3][3] ={0};

    for (int m=0;m<3;m++){ 
        for (int n=0;n<3;n++){
            for(int i=0;i<3;i++){
                    temp[m][n] += (B.x[m][i])*(x[i][n]);
            }
        }
    }

    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            x[i][j] = temp[i][j];
        }
    }
}

void Matrix::rMult(Matrix B){
    double temp[3][3] ={0};

    for (int m=0;m<3;m++){ 
        for (int n=0;n<3;n++){
            for(int i=0;i<3;i++){
                temp[m][n] += (x[m][i])*(B.x[i][n]);
            }
        }
    }

    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            x[i][j] = temp[i][j];
        }
    }
}

void Matrix::sMult(double s){
    for (int m=0;m<3;m++){ 
        for (int n=0;n<3;n++){
            x[m][n]*=s;   
    }    
        }
}

double Matrix::det(){
    double diagonal = 0.0;
    double anti_diagonal = 0.0;

    for(int n=0;n<3;n++){
        diagonal += x[0][n] * x[1][(n+1)%3] * x[2][(n+2)%3];
    }

    for(int n=2;n>=0;n--){
        anti_diagonal += x[0][n] * x[1][(n+2)%3] * x[2][(n+1)%3];
    }

    double determinant = diagonal - anti_diagonal;
    cout << "Determinant is: " << determinant << endl;
    return determinant;
}

void Matrix::inv(){
    double determinant = det();
    if(determinant !=0){
        Matrix core; 
        for (int n=0;n<3;n++) {
            for (int index=0;index<3;index++) {
                core.x[n][index] = ((x[(n+1)%3][(index+1)%3]) * (x[(n+2)%3][(index+2)%3])) - 
                ((x[(n+1)%3][(index+2)%3]) * (x[(n+2)%3][(index+1)%3]));
            }
        }
        core.transpose();

        for(int m=0;m<3;m++){
            for(int n=0;n<3;n++){
                x[m][n] = (1/determinant)*(core.x[m][n]);
            }
        }
    }
}