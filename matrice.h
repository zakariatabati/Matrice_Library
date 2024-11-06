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
};
















#endif