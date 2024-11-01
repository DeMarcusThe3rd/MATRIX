#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "matrix.h"

using namespace std;

void Matrix::print(){
    for (int m=0;m<3;m++){ //loop through the rows
        for (int n=0;n<3;n++){ //loop through the columns
            cout << "[" << setw(7) << fixed << setprecision(3) << x[m][n] << "]" << "  ";  //print elements with formatting
        }
        cout << endl; //new line every 3 elements (row) 
    }
    cout << endl; 
}

void Matrix::set(double a,double b,double c,double d,double e,double f,double g,double h,double i){ //set all elements of the matrix 
    double values[9] = {a,b,c,d,e,f,g,h,i};  //input for the values of the 3x3
    int index=0;    

    for (int m=0;m<3;m++){     //nested for loop to iterate through indexes mn [row][column] of the array 
        for (int n=0;n<3;n++){     
            x[m][n] = values[index++]; //set the element at the specific matrix index 
        }
    }
}

void Matrix::set(int m, int n, double elem){ //set one specific element of the matrix 
    if ((m>=0 && m<3) &&(n>=0 && n<3)){ //condition for the input index to be within bounds (0 to 2)
        x[m][n] = elem; //set the element at the specific matrix index 
    }
    else{
        cout << "Matrix is 3x3, Index out of Bounds" <<endl;  //prints error message 
    }
}

double Matrix::getElem(int m, int n){  //get element at the specified index 
    cout << x[m][n];  //displays the element retrieved 
    return x[m][n];  //returns the element as a double for calculation purposes 
}

void Matrix::transpose(){  //tranposes the current matrix (swaps row with column and vice versa) 
    for (int m=0;m<3;m++){  //nested for loop to iterate through indexes mn [row][column] of the array 
        for (int n=m;n<3;n++){
            double temp = x[m][n];  //temporarily stores element at the specific index in variable temp  
            x[m][n] = x[n][m];     //swap the element 
            x[n][m] = temp;        //swap the element 
        }
    }   
}

void Matrix::eye(){   //sets the current matrix to the identity matrix (1 along diagonal, 0 elsewhere)
    for (int m=0;m<3;m++){  //nested for loop to iterate through indexes mn [row][column] of the array 
        for(int n=0;n<3;n++){
            if (m==n){      //condition to check if row index is equal to column index (check if on diagonal)
                x[m][n] = 1.0; //set to 1
            }
            else{
                x[m][n] = 0.0;  //set to 0 
            }
        }
    }
}

void Matrix::zero(){  //sets the current matrix to a zero matrix 
    for (int m=0;m<3;m++){  //nested for loop to iterate through indexes mn [row][column] of the array 
        for(int n=0;n<3;n++){
            x[m][n] = 0.0;  //set to 0 
        }
    }
}

void Matrix::save(string filename){  //saves a matrix in a .txt file 
    ofstream savef(filename);  //declare "savef" as output stream to a file 

    if(savef.is_open()){  //condition to check if file is opened successfully 
        for (int m=0;m<3;m++){   //nested for loop to iterate through indexes mn [row][column] of the array 
                for (int n=0;n<3;n++){  
                    savef << x[m][n] << " ";  //saves element read into output file stream with formatting 
                }
                savef << endl;  //new line after every 3 elements 
            }
        }
    else{
        cout << "Error writing to file." <<endl;  //error message displayed if file not found 
    }
    savef.close();  //closes file stream regardless
}


void Matrix::load(string filename){  //loads a matrix saved in a .txt file 
    ifstream loadf(filename);  //declare "loadf" as an input file stream to a file 
    
    if(loadf.is_open()){  //condition to check if file is opened successfully 
        for (int m=0;m<3;m++) {  //nested for loop to iterate through indexes mn [row][column] of the array 
            for (int n=0;n<3;n++) {
                loadf >> x[m][n];  //loads elements saved into the matrix
            }
        }
    }

    else{
        cout << "Error opening file." << endl; //error message displayed if file not found. 
    }
    loadf.close();  //closes file stream regardless 
}

void Matrix::add(Matrix B){  //adds current matrix with another matrix 
     for (int m=0;m<3;m++){ //nested for loop to iterate through indexes mn [row][column] of the array 
        for (int n=0;n<3;n++){
            x[m][n]+= B.x[m][n];  //sumation of current element with element of the other matrix 
        }
    }
}

void Matrix::sub(Matrix B){ //subtracts current matrix with another matrix 
    for (int m=0;m<3;m++){  //nested for loop to iterate through indexes mn [row][column] of the array 
        for (int n=0;n<3;n++){
            x[m][n]-= B.x[m][n];  //subtraction of current element with element of the other matrix   
        }
    }
}

double Matrix::rcMult(Matrix B,int row, int col){  //dot product between current matrix with another matrix 
    double result = 0.0; //variable to be returned after calculation 
    for(int i=0;i<3;i++){  //iterates through the elements along the row and column
        result += (x[row][i])*(B.x[i][col]);  
    }
    cout << "Dot Product: " << result << endl; //displays the result 
    return result; //returns the result 
}

void Matrix::lMult(Matrix B){  //multiples another matrix with current matrix 
    double temp[3][3] ={0};  //temporary matrix to store results of the operation

    for (int m=0;m<3;m++){  //nested for loop to iterate through indexes mn [row][column] of the array 
        for (int n=0;n<3;n++){
            for(int i=0;i<3;i++){  //for loop to interate through row of one matrix and column of one matrix simultaneously 
                    temp[m][n] += (B.x[m][i])*(x[i][n]);  
            }
        }
    }

    for (int m=0;m<3;m++){  //nested for loop to iterate through indexes mn [row][column] of the array 
        for(int n=0;n<3;n++){
            x[m][n] = temp[m][n];  //copies values stored in temporary into main matrix 
        }
    }
}

void Matrix::rMult(Matrix B){  //multiples another matrix with current matrix 
    double temp[3][3] ={0};  //temporary matrix to store results of the operation

    for (int m=0;m<3;m++){ //nested for loop to iterate through indexes mn [row][column] of the array 
        for (int n=0;n<3;n++){
            for(int i=0;i<3;i++){  //for loop to interate through row of one matrix and column of one matrix simultaneously 
                temp[m][n] += (x[m][i])*(B.x[i][n]);
            }
        }
    }

    for (int m=0;m<3;m++){  //nested for loop to iterate through indexes mn [row][column] of the array 
        for(int n=0;n<3;n++){
            x[m][n] = temp[m][n];  //copies values stored in temporary into main matrix 
        }
    }
}

void Matrix::sMult(double s){  //multiplies current vector by a scalar "s"
    for (int m=0;m<3;m++){   //nested for loop to iterate through indexes mn [row][column] of the array 
        for (int n=0;n<3;n++){
            x[m][n]*=s;   
    }    
        }
}

double Matrix::det(){  //calculates and returns the determinant of current matrix 
    double diagonal = 0.0;  //diagonal of the matrix 
    double anti_diagonal = 0.0; //antidiagonal of the matrix 

    for(int n=0;n<3;n++){  //iterates and sums through the diagonal of the matrix 
        diagonal += x[0][n] * x[1][(n+1)%3] * x[2][(n+2)%3]; //utilizing modulo to return to safe index beyond 2 
    }

    for(int n=2;n>=0;n--){  //iterate and sums through the anti-diagonal of the matrix 
        anti_diagonal += x[0][n] * x[1][(n+2)%3] * x[2][(n+1)%3]; //utilizing modulo to return to safe index beyond 2 
    }

    double determinant = diagonal - anti_diagonal;  //subtraction to obtain the determinant 
    cout << "Determinant is: " << determinant << endl;  //displays the determinant 
    return determinant;   //returns the determinant 
}

void Matrix::inv(){  //calculates the inverse of the current matrix 
    double determinant = det();  //declare determinant 
    if(determinant !=0){  
        Matrix core; //matrix to store the cofactors of the current matrix 
        for (int m=0;m<3;m++) {   //nested for loop to iterate through indexes mn [row][column] of the array 
            for (int n=0;n<3;n++) {
                core.x[m][n] = ((x[(m+1)%3][(n+1)%3]) * (x[(m+2)%3][(n+2)%3])) - 
                ((x[(m+1)%3][(n+2)%3]) * (x[(m+2)%3][(n+1)%3])); //utilizing modulo to return to safe index beyond 2 
            }
        }
        core.transpose();  //tranpose the core factors 

        for(int m=0;m<3;m++){  //nested for loop to iterate through indexes mn [row][column] of the array 
            for(int n=0;n<3;n++){
                x[m][n] = (1/determinant)*(core.x[m][n]); 
            }
        }
    }
    else{
        cout << "This Matrix is singular and has no inverse." <<endl;  //message to notify non-inverse matrix
    }
}