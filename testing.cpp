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
    Matrice X(3,3),D(3,2);
    float arr[3] = {1,2,3};
    X.eye(arr);
    X.zeros();
    X.print();
    D.ones();
    D.print();
    A.replace(2,2,7);
    A.print();
    cout<<A.Max()<<"    "<<A.Min()<<endl;
    (A.ADD(B)).print();
    (A.SOUS(B)).print();
    (D.MULT_BY_SCALAR(6)).print();

    (D.Mult(A)).print();
    return 0;
}
