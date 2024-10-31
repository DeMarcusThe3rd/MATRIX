#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;

class Matrix
{
private:
    double x[3][3]; //initializes the 3x3 matrix 

public:
    void print(); 
    void set(int m ,int n, double elem);
    void set(double a,double b,double c,double d,double e,double f,double g,double h,double i);
    double getElem(int m, int n);
    void transpose();
    void eye();
    void zero();
    void save(string filename);
    void load(string filename);
    void add(Matrix B);
    void sub(Matrix B);
    double rcMult(Matrix B,int row, int col);
    void lMult(Matrix B);
    void rMult(Matrix B);
    void sMult(double s);
    double det(); 
    void inv();
};