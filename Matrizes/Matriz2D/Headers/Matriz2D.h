#ifndef MATRIZ2D_H
#define MATRIZ2D_H

#include <iostream>

class Matriz2D{

    public:
        Matriz2D(int nnl, int nnc);
        ~Matriz2D();
        float get(int i, int j);
        void set(int i, int j, float valor);
        void print();
        void printColumnX(int columnNumber);
        void transposta();
        float CalcSecundarieDiagonal();
        float getForMatBecameToUniVector(int i , int j);
        void MatrixWhateverIndices(int c1 , int c2 ,int f1, int f2);
        void getMatTriToVet();
        
        private:

        void fillUniVector();

        int numberOflines; // numero de linhas
        int numberOfColumns; // numero de colunas
        int lowerLimit=0;
        int upperLimit=0;
        int matWhtNumLines=0;
        int matWhtNumColumns=0;
        int MatTriToVetLength=0;


        float **mat=nullptr; // array com nl*nc floats
        float **matTrans= nullptr;
        float *MatBecameToUniVector=nullptr;
        bool verific(int i, int j);
        float *MatTriToVet=nullptr;
};

#endif