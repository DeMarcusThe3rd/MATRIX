#include <iostream>
#include <iomanip>
#include <vector>

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
};


