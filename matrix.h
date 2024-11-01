#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;

class Matrix  //intialize a class named Matrix 
{
private:
    /*Class Variables*/
    double x[3][3]; //initializes the 3x3 matrix 

public:
    /*Methods*/
    void print(); //displays all elements of the current matrix 
    void set(int m ,int n, double elem); //set all elements of the matrix 
    void set(double a,double b,double c,double d,double e,double f,double g,double h,double i); //set one specific element of the matrix 
    double getElem(int m, int n); //get element at the specified index 
    void transpose(); //tranposes the current matrix (swaps row with column and vice versa) 
    void eye(); //sets the current matrix to the identity matrix (1 along diagonal, 0 elsewhere)
    void zero();  //sets the current matrix to a zero matrix 
    void save(string filename);  //saves a matrix in a .txt file 
    void load(string filename);  //loads a matrix saved in a .txt file 
    void add(Matrix B);  //adds current matrix with another matrix 
    void sub(Matrix B);   //subtracts current matrix with another matrix 
    double rcMult(Matrix B,int row, int col);  //dot product between current matrix with another matrix 
    void lMult(Matrix B);  //multiples another matrix with current matrix 
    void rMult(Matrix B);  //multiples another matrix with current matrix 
    void sMult(double s); //multiplies current vector by a scalar "s"
    double det(); //calculates and returns the determinant of current matrix 
    void inv(); //calculates the inverse of the current matrix 
};