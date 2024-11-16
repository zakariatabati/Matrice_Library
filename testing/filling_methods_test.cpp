#include "C:\Users\zakar\Desktop\Matrice_library\matrice.h"
#include<iostream>
using namespace std;
int main()
{

    Matrice A(2,2);//Create a Matrice of size 2x2
    A.fill();//first way of fill by values
    Matrice B(A);//copy Matrice A in B
    A.print();//print Matrice
    B.print();
    Matrice C(3,3);
    C.fill(5);//second way of fill fill all the matrice by one values
    C.print();
    Matrice X(3,3),D(3,2);
    float arr[3] = {1,2,3};
    X.eye(arr);//Matrice diagonale 
    X.zeros();//fill all the matrice by zeros
    X.print();
    D.ones();//fill all the matrice by ones
    D.print();
    return 0;
}
