#include "matrice.h"
#include<iostream>
#include<bits/stdc++.h>
#include <stdexcept>
using namespace std;

/**
 * @brief Construct a new Matrice:: Matrice object
 * 
 * @param r 
 * @param c 
 */
Matrice::Matrice(int r,int c)
{
    /**
        * @brief Construct a new Matrice:: Matrice object
        * 
        * @param r 
        * @param c 
    */
    
    row = r;
    column = c;
    data = new float *[row];
    for(int i=0;i<r;i++ )
        data[i] = new float[column];
}


Matrice::Matrice(const Matrice &M)
{
   /**
        * @brief Construct(Copy) a new Matrice:: Matrice object
        * 
        * @param M 
    */ 
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
    /**
     * @brief Destructeur of Matrice
     * 
     */
    
    for(int i=0;i<row;i++)
        delete [] data[i];
    delete [] data;
}
void Matrice::print()
{
    /**
     * @brief Print a Matrice values
     * 
     * 
     */
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
    /**
     * @brief Fill a Matrice
     * 
     * 
     */
    for(int i=0;i<this->row;i++)
    {
        for(int j=0;j<this->column;j++)
            cin>>this->data[i][j];
    }

}
void Matrice::fill(float value)
{
    /**
     * @brief Fill a Matrice by one values
     * @param value
     */
    for(int i=0;i<this->row;i++)
        for(int j=0;j<this->column;j++)
            this->data[i][j] = value;
}
void Matrice::eye(float *t)
{
    /**
     * @brief Make matrice diago
     * @param t 
     */
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
    /**
     * @brief Fill Matrice by Ones
     * 
     */
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            data[i][j] = 1;
    }
}
void Matrice::zeros()
{
    /**
     * @brief Fill Matrice by Zeros
     * 
     */
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            data[i][j]=0;
    }
}
void Matrice :: replace(int i,int j,float new_element)
{
    /**
     * @brief Replace a value in Matrice 
     * @param new_element 
     */
    data[--i][--j] = new_element;
}
/**
 * @brief Return a Min value in Matrice 
 * 
 * @return float 
 */
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
/**
 * @brief Return Max value in Matrice
 * 
 * @return float 
 */
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
/**
 * @brief ADD method
 * 
 * @param A 
 * @return Matrice 
 */
Matrice Matrice :: ADD(const Matrice &A)
{
   if (row != A.row || column != A.column) {
            throw std::logic_error("Addition requires matrices of the same dimensions");
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
/**
 * @brief Subtraction method
 * 
 * @param A 
 * @return Matrice 
 */
Matrice Matrice :: SOUS(const Matrice &A)
{
    if (row != A.row || column != A.column) {
            throw std::logic_error("Subtraction requires matrices of the same dimensions");
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
/**
 * @brief Multiple Matrice by a value
 * 
 * @param lambda 
 * @return Matrice 
 */
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
/**
 * @brief Multiplication method
 * 
 * @param A 
 * @return Matrice 
 */
Matrice Matrice :: Mult(const Matrice &A)
{
    if (column != A.row) {
            throw std::logic_error("Multiplication requires column of first matrix to match row of second matrix");
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
/**
 * @brief + operator
 * 
 * @param A 
 * @return Matrice 
 */
Matrice Matrice ::operator+(const Matrice &A)
{
    if (row != A.row || column != A.column) {
            throw std::logic_error("Addition requires matrices of the same dimensions");
        }
    Matrice C(row,column);

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            C.data[i][j] = data[i][j] + A.data[i][j];
    }

    return C;

}
/**
 * @brief - operator
 * 
 * @param A 
 * @return Matrice 
 */
Matrice Matrice ::operator-(const Matrice &A)
{
     if (row != A.row || column != A.column) {
            throw std::logic_error("Subtraction requires matrices of the same dimensions");
        }
    Matrice C(row,column);

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
            C.data[i][j] = data[i][j] - A.data[i][j];
    }

    return C;

}
/**
 * @brief * operator
 * 
 * @param A 
 * @return Matrice 
 */
Matrice Matrice ::operator*(const Matrice &A)
{
     if (column != A.row) {
            throw std::logic_error("Multiplication requires column of first matrix to match row of second matrix");
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
/**
 * @brief Compare operator
 * 
 * @param A 
 * @return true 
 * @return false 
 */
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
/**
 * @brief 
 * 
 * @param A 
 * @return true 
 * @return false 
 */
bool Matrice::operator!=(const Matrice &A)
{
    return (!(*this==A));
}

/**
 * @brief 
 * 
 * @param A 
 * @return Matrice& 
 */
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
/**
 * @brief Trace method
 * 
 * @return float 
 */
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




