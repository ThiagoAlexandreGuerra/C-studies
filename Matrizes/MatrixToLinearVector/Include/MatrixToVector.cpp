#include "MatrixToVector.h"
#include <iostream>

using namespace std;

MatToVet::MatToVet(int c1, int c2 , int f1 , int f2){

    LinesAmount=f1-c1 +1;
    ColumnsAmount=f2-c2 +1;
    
    whateverMatrixIndices=new float*[LinesAmount]();
    for(int i=0 ; i<LinesAmount ; i++){
        whateverMatrixIndices[i]=new float[ColumnsAmount]();
    }
    
    int k=0;
    LinearVector=new float[LinesAmount*ColumnsAmount];

    for(int i=0 ; i<LinesAmount ; i++){
        for(int j=0 ; j<ColumnsAmount; j++){
            k=(ColumnsAmount*i)+j;
            LinearVector[k]=whateverMatrixIndices[i][j];
        }
    }

    
}

MatToVet::~MatToVet(){

    for(int i=0 ; i<LinesAmount; i++){
        delete []whateverMatrixIndices[i];
    }
    delete []whateverMatrixIndices;

    delete []LinearVector;
}

void MatToVet::setValue(int i, int j , float value){

    int k=0;
    k=(j-C2)+(i-C1)*ColumnsAmount;
    LinearVector[k]=value;
}

float MatToVet::getValue(int i , int j){

    int k=detInt(i,j);

    return k;
}

int MatToVet::detInt(int i, int j){

    int k=0;
    if(((i>=C1) && (i<=F1)) && ((j>=C2) && (j<=F2)) ){
        k=(j-C2)+(i-C1)*ColumnsAmount;
        return k;
    }else{
        cout<<"Invilid Indices!!! Make sure the values and try again"<<endl;
    }
}