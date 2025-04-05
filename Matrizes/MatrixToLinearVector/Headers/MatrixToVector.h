#ifndef MATRIXTOVECTOR_H
#define MATRIXTOVECTOR_H

#include <iostream>

class MatToVet{

    private:
        int lowerLimit=0;
        int UpperLimit=0;
        int LinesAmount=0;
        int ColumnsAmount=0;
        int C1=0;
        int F1=0;
        int C2=0;
        int F2=0;

        float **whateverMatrixIndices=nullptr;
        float *LinearVector=nullptr;
        float *vetMatTriSup=nullptr;
    public:

        MatToVet(int c1, int c2 , int f1 , int f2);
        ~MatToVet();
        void setValue(int i , int j, float value);
        float getValue(int i , int j);
        int detInt(int i , int j);


};
#endif