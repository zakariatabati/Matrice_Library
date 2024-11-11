#ifndef _MATRICE_
#define _MATRICE_


class Matrice
{
private:
    int row ,column;
    float **data;
    
public:
    Matrice(int,int);
    Matrice(const Matrice&);
    ~Matrice();
    void print();
    void fill();
    void fill(float);
    void zeros();
    void ones();
    void eye(float *t);
    void replace(int i,int j , float new_element );
    float Min();
    float Max();
    Matrice ADD(const Matrice &);
    Matrice SOUS(const Matrice &);
    Matrice Mult(const Matrice &);
    Matrice MULT_BY_SCALAR(float lambda);
};
















#endif