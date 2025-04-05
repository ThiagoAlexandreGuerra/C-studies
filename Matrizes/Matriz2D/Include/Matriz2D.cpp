#include "Matriz2D.h"
#include <iostream>

using namespace std;

Matriz2D::Matriz2D(int n , int m){

    numberOflines=n;
    numberOfColumns=m;

    mat=new float*[numberOflines]();
    for(int i=0 ; i<numberOflines ; i++){
        mat[i]=new float[numberOfColumns]();
    }

    int k=0;
    MatTriToVetLength=n*((n+1)/2);
    MatTriToVet=new float[MatTriToVetLength]();

    
    cout<<endl<<"your matrix 2D was accomplishied with success."<<endl;
    
}

Matriz2D::~Matriz2D(){

    for(int i=0 ; i<numberOflines ; i++){
        delete [] mat[i];
    }
    delete []mat;

    for(int i=0 ; i<numberOfColumns ; i++){
        delete [] matTrans[i];
    }

    delete []matTrans;

    delete []MatBecameToUniVector;
}

bool Matriz2D::verific(int i , int j){

    if(((i>=0)&&(i<numberOflines)) && ((j>=0)&&(j<numberOfColumns))){
        return true;
    }else{
        return false;
    }
}

void Matriz2D::set(int i , int j , float value){

    if(verific(i,j)){
        mat[i][j]=value; 
        cout<<endl<<"This operation was accomplished with success."<<endl;
    }else{
        cout<<endl<<endl<<"The indices i and j are invalid!!!!"<<endl;
        cout<<" , ensure that be a correct value and try again"<<endl;
        exit(1);
    }
}

float Matriz2D::get(int i, int j){

    if(verific(i,j)){
        cout<<"Matriz2D ["<<i<<"]["<<j<<"]"<<"="<<mat[i][j];
        return mat[i][j];
    }else{
        cout<<endl<<endl<<"The indices i and j are invalid!!!!"<<endl;
        cout<<" , ensure that be a correct value and try again"<<endl;
        exit(1);
        
    }
}

void Matriz2D::print(){

    cout<<endl<<endl;

    for(int i=0 ; i<numberOflines ; i++){
        for(int j=0; j<numberOfColumns ; j++){

            cout<<mat[i][j]<<"   ";
        }
        
        cout<<endl;    
    }
}

void Matriz2D::printColumnX(int columnNumber){

    cout<<endl<<endl<<"Print of column "<<columnNumber<<"_____________________________________:"<<endl;
    if(verific(0 , columnNumber)){
        for(int i=0 ; i<numberOflines ; i++){
            cout<<mat[i][columnNumber]<<endl;
        }
    }else{
        cout<<"the column no exist , try again"<<endl;
    }
    cout<<"__________________________________________________________________________|";
};

void Matriz2D::transposta(){

    cout<<endl<<endl;

    matTrans= new float*[numberOfColumns]();
    for(int i=0; i<numberOfColumns ; i++){
        matTrans[i]=new float[numberOflines]();
    }

    for(int i=0 ; i<numberOfColumns ; i++){
        for(int j= 0 ;j<numberOflines ; j++){
            matTrans[i][j]=mat[j][i];
        }
    }

    for(int i=0 ; i<numberOfColumns ; i++){
        for(int j= 0 ;j<numberOflines ; j++){
           cout<<matTrans[i][j]<<"   ";
        }
        cout<<endl;
    }
    
}

float Matriz2D::CalcSecundarieDiagonal(){

    cout<<endl<<"The secondary diagonal___________________________________________: "<<endl<<endl;
    
    float theLagestValue=0;
    int j=0;

    for(int i=0 ; i<numberOflines ; i++){

        j=(numberOfColumns-1-i) ;

        if(mat[i][j]>theLagestValue){
            theLagestValue=mat[i][j];
        }
         
    }

    for(int i=0 ; i<numberOflines ; i++){

        j=(numberOfColumns-1-i) ;
        cout<<mat[i][j]<<endl;
    }

    cout<<endl<<"The largest value of secundary diagonal is: "<<theLagestValue<<endl;

    cout<<endl<<"_____________________________________________________________________________|"<<endl;
    return theLagestValue;
    
}

void Matriz2D::fillUniVector(){

    int lenght= numberOfColumns*numberOflines;
    int k=0;

    MatBecameToUniVector=new float[lenght]();
    
    for(int i=0 ; i<numberOflines ; i++){
        for(int j=0 ; j<numberOfColumns ; j++){
            k=((numberOfColumns*i)+j);
            MatBecameToUniVector[k]=mat[i][j];
        }
    }

    for(int i=0; i<lenght ; i++){
        cout<<MatBecameToUniVector[i]<<" ";
    }
    cout<<endl;
}

float Matriz2D::getForMatBecameToUniVector(int i , int j){

    fillUniVector();
    
    int k=0;
    if(verific(i,j)){
        k=(numberOfColumns*i)+j;
        return MatBecameToUniVector[k];
    }else{
        cout<<endl<<endl<<"The indices i and j are invalid!!!!"<<endl;
        cout<<" , ensure that be a correct value and try again"<<endl;
        exit(1);
    }

}

void Matriz2D::MatrixWhateverIndices(int c1 , int c2 ,int f1, int f2  ){

    matWhtNumLines= f1 - c1 +1;
    matWhtNumColumns= f2 - c2 +1 ; 

    
}

void Matriz2D::getMatTriToVet(){

    int k=0;
    
    for(int i=0 ; i<numberOflines ; i++){
        for(int j=0 ; j<numberOfColumns ; j++){
            k=(((i+1)*i)/2)+j;
            
            if(i>=j){
                MatTriToVet[k]=mat[i][j];
            }
        }
    }


    cout<<endl<<endl<<"getMatTriToVet__________________________________________________________:"<<endl;
    for(int k=0 ; k<MatTriToVetLength ; k++){
        cout<<MatTriToVet[k];
    }
    cout<<endl<<"__________________________________________________________________________|"<<endl;
}