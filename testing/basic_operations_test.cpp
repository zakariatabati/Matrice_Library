#include "C:\Users\zakar\Desktop\Matrice_library\matrice.h"
#include<iostream>
using namespace std;
int main()
{

    Matrice A(2,2);
    A.fill();
    Matrice B(A);
    Matrice C(3,3);
    C.fill(5);
    A.replace(2,2,7);//replace A[2][2] by 7
    cout<<A.Max()<<" "<<A.Min()<<endl;//cout the Max/Min element in your Matrice
    cout<<"----------------------------"<<endl;
    Matrice X(2,2);
    X = A+B;
    X.print();
    X = A-B ; 
    X.print();
    X = C*A ;
    X.print();
    return 0;
}
