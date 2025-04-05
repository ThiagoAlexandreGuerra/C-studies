#include <iostream>
using namespace std;

void reading(int vet[] , int len){

    for(int i=0 ; i<len ; i++){
        cout<<"position: "<<i<<" value: "<<vet[i]<<endl;
    }
    cout<<"-----------------------------------------------------------------|";
    cout<<endl;

}

void ReverseTheArrey(int vector[] , int length){

    int aux=0;

    for(int i=0 ; i<(length/2) ; i++){

        aux=vector[i];
        vector[i]=vector[length-1-i];
        vector[length-1-i]=aux;

    };

    reading(vector, length);
}



int main(){

    int vet[11]={11,10, 9 , 8 , 7 , 6, 5 , 4, 3, 2, 1};

    ReverseTheArrey(vet , 11);
    
    return 0;
    
}