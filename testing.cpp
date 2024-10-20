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
    return 0;
}
