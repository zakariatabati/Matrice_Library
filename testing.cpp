#include "matrice.h"
#include<iostream>
using namespace std;
int main()
{

    Matrice A(2,2);
    A.fill();
    Matrice B(A);
    A.print();
    B.print();
    Matrice C(3,3);
    C.fill(5);
    C.print();
    Matrice X(3,3),D(2,3);
    float arr[3] = {1,2,3};
    X.eye(arr);
    X.zeros();
    X.print();
    D.ones();
    D.print();

    return 0;
}
