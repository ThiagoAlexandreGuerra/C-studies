#include "Matriz2D.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main(){

    int n=0 , m=0 , i=0 , j=0 , k=0 , AskForContinue=0;
    float value;
    bool CONTINUE=true , yesORno=true;
    cout<<"Welcome to the matriz2D program , write the num of lines end columns below: "<<endl<<endl;
    cout<<"Num of lines: ";
    cin>>n;
    cout<<"Num of columns: ";
    cin>>m;

    Matriz2D matrix(n,m);
    srand(time(nullptr));

    for(int l=0 ; l<n ; l++){
        for(int c=0; c<m ; c++){
            value=rand()%100+1; 
            matrix.set(l,c,value);
        }
    }
    while (CONTINUE)
    {
        
        cout<<endl<<endl;
        cout<<"Now you can set the values of your matrix 2D , Write the indices i and j and the value: "<<endl<<endl;
        cout<<"index i: ";
        cin>>i;
        cout<<"index j: ";
        cin>>j;
        cout<<"Now write a value for the positio ["<<i<<"]["<<j<<"]: ";
        cin>>value;
        matrix.set(i , j , value);

        if((AskForContinue%10) == 0){
            cout<<"Do you can continue seting the values of your matrix2D?"<<endl;
            cout<<"press 1 for continue or 0 for exit: ";
            cin>>CONTINUE;
            cout<<endl; 
        }

    }
    

    cout<<"Do you want find a specific value of your Matrix2D ?"<<endl;
    cout<<"if you want continue press 1, otherwise press 0: ";
    cin>>yesORno;
    cout<<endl;

    if(yesORno){
        cout<<"write bellow the index i and j of value, which you want find the value: "<<endl;
        cout<<"index i: ";
        cin>>i;
        cout<<"index j: "; 
        cin>>j;
        matrix.get(i,j);
        
    }

    cout<<"Do you want print a specific column of your Matrix2D ?"<<endl;
    cout<<"if you want continue press 1, otherwise press 0: ";
    cin>>yesORno;

    if(yesORno){
        cout<<"write bellow the column, which you want find the values: "<<endl;

        cout<<"Column number: "; 
        cin>>j;
        matrix.printColumnX(j);
        
    }

    matrix.print();

    matrix.transposta();

    matrix.CalcSecundarieDiagonal();

    
    cout<<endl<<"your Matriz2D was transformend in a unidimentional vector"<<endl;
    cout<<"for acess the indices write the values of i and j: "<<endl<<endl;
    cout<<"i: ";
    cin>>i;
    cout<<"j: ";
    cin>>j;

    float y=0;

    

    y=matrix.getForMatBecameToUniVector(i,j);
    cout<<"the value in index["<<i<<"]["<<j<<"] is: "<<y<<endl;
    matrix.getMatTriToVet();
    return 0;


}