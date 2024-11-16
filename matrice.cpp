#include "matrice.h"
#include<iostream>
#include<bits/stdc++.h>
#include <stdexcept>
using namespace std;


Matrice::Matrice(int r,int c)
{
    //cout<<"creat"<<endl;
    row = r;
    column = c;
    data = new float *[row];
    for(int i=0;i<r;i++ )
        data[i] = new float[column];
}

Matrice::Matrice(const Matrice &M)
{
    //cout<<"copy"<<endl;
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
    //cout<<"delete"<<endl;
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
void Matrice :: replace(int i,int j,float new_element)
{
    data[--i][--j] = new_element;
}
float Matrice::Min()
{
    float min_value = data[0][0];
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<column;j++)
        {
            min_value = min(min_value,data[i][j]);
        }
    }
    return min_value;
}

float Matrice::Max()
{
    float max_value = data[0][0];
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<column;j++)
            max_value = max(max_value,data[i][j]);
    }

    return max_value;
}

Matrice Matrice :: ADD(const Matrice &A)
{
    if(row!=A.row || column!=A.column)
    {
        cout<<"ERROR !!!!!!"<<endl;
        exit(-1);
    }
    Matrice R(row,column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            R.data[i][j] = data[i][j] + A.data[i][j];
        }
    }
    return R;
}

Matrice Matrice :: SOUS(const Matrice &A)
{
    if(row!=A.row || column!=A.column)
    {
        cout<<"ERROR !!!!!!"<<endl;
        exit(-1);
    }
    Matrice R(row,column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            R.data[i][j] = data[i][j] - A.data[i][j];
        }
    }
    return R;
}

Matrice Matrice :: MULT_BY_SCALAR(float lambda)
{
    Matrice R(this->row,this->column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            R.data[i][j] = lambda * data[i][j];
        }
    }
    return R;
}

Matrice Matrice :: Mult(const Matrice &A)
{
    if(column!=A.row)
    {
        cout<<"ERROR !!!!!!"<<endl;
        exit(-1);
    }
    Matrice R(row,A.column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<A.column;j++)
        {
            for(int k=0;k<column;k++)
                R.data[i][j] += data[i][k] * A.data[k][j];
        }
    }
    return R;
}

Matrice Matrice ::operator+(const Matrice &A)
{
    if(row!=A.row || column!=A.column)
    {
        cout<<"ERROR !!!!!!"<<endl;
        exit(-1);
    }
    Matrice C(row,column);

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            C.data[i][j] = data[i][j] + A.data[i][j];
    }

    return C;

}

Matrice Matrice ::operator-(const Matrice &A)
{
    if(row!=A.row || column!=A.column)
    {
        cout<<"ERROR !!!!!!"<<endl;
        exit(-1);
    }
    Matrice C(row,column);

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            C.data[i][j] = data[i][j] - A.data[i][j];
    }

    return C;

}
Matrice Matrice ::operator*(const Matrice &A)
{
    if(column!=A.row)
    {
        cout<<"ERROR !!!!!!"<<endl;
        exit(-1);
    }
    Matrice C(row,A.column);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<A.column;j++)
        {
            for(int k=0;k<column;k++)
                C.data[i][j] += data[i][k] * A.data[k][j];
        }
    }
    return C;

}

bool Matrice::operator==(const Matrice &A)
{
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
        {
            if(data[i][j]!=A.data[i][j])
                return 0;
        }
    return 1;    
}

bool Matrice::operator!=(const Matrice &A)
{
    return (!(*this==A));
}


Matrice& Matrice::operator=(const Matrice &A)
{
    if(*this ==A)
    {
        return *this;
    }
    for(int i=0;i<row;i++)
        delete [] data[i];
    delete [] data;

    row = A.row;
    column = A.column;

    data = new float *[row];
    for(int i=0;i<row;i++ )
        data[i] = new float[column];
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            data[i][j] = A.data[i][j];
    }

    return *this;

}

float Matrice::trace()
{
     if (row != column) 
        {
            throw std::logic_error("Trace can only be calculated for square matrices");
        }
    float sum=0;
    for(int i=0;i<row;i++)
        sum+=data[i][i];
    return sum;
}




