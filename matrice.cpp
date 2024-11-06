#include "matrice.h"
#include<iostream>
using namespace std;


Matrice::Matrice(int r,int c)
{
    cout<<"creat"<<endl;
    row = r;
    column = c;
    data = new float *[row];
    for(int i=0;i<r;i++ )
        data[i] = new float[column];
}

Matrice::Matrice(const Matrice &M)
{
    cout<<"copy"<<endl;
    this->row = M.row;
    this->column = M.column;
    this->data = new float*[this->row];
    for(int i=0;i<this->row;i++)
        this->data[i] = new float[this->column];
    
    for(int i=0;i<this->row;i++)
        for(int j=0;j<this->column;j++)
            this->data[i][j] = M.data[i][j];

}

Matrice::~Matrice()
{
    cout<<"delete"<<endl;
    for(int i=0;i<row;i++)
        delete [] data[i];
    delete [] data;
}
void Matrice::print()
{
    for(int i=0;i<this->row;i++)
    {
        for(int j=0;j<this->column;j++)
        {
            cout<<this->data[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Matrice::fill()
{
    for(int i=0;i<this->row;i++)
    {
        for(int j=0;j<this->column;j++)
            cin>>this->data[i][j];
    }

}
void Matrice::fill(float value)
{
    for(int i=0;i<this->row;i++)
        for(int j=0;j<this->column;j++)
            this->data[i][j] = value;
}
void Matrice::eye(float *t)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(i==j)
                data[i][j] = t[i];
            else
                data[i][j] = 0;
        }
    }

}
void Matrice ::ones()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            data[i][j] = 1;
    }
}
void Matrice::zeros()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            data[i][j]=0;
    }
}