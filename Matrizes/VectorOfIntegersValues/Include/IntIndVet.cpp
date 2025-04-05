#include "IntIndVet.h"
#include <iostream>

using namespace std;

IntIndVet::IntIndVet(int LowerLimit , int UpperLimit){

    range=UpperLimit-LowerLimit;
    LLowerLimit=LowerLimit;
    UUpperLimit=UpperLimit;
    int rrange=range;

    vector=new int[rrange]();

}

IntIndVet::~IntIndVet(){

    delete []vector;
}

void IntIndVet::UpdateCapacity(){

    capacity=(occupy/(static_cast<float>(range)))*(100);
    
}

void IntIndVet::setValues(){

    int value=0, i=0, contForAsk=1;
    bool CONTINUE=true;

    cout<<"Write a integer values for your FlexVector: "<<endl;
    
    while(CONTINUE && (i<range)){

        cout<<"FlexVector["<<(LLowerLimit+i)<<"] :";
        cin>>value;
        vector[i]=value;
        i++;
        occupy++;

        if(((contForAsk % 5) && (i<range) ) == 0){

            cout<<"press 1 for continue or 0 for exist: ";
            cin>>CONTINUE;
            cout<<endl;
        }

        if(i==(range-1)){
            cout<<"your vector is fulled"<<endl;
        }

        contForAsk++;
    }
}

void IntIndVet::getAllValues(){

    cout<<endl<<endl;
    UpdateCapacity();
    cout<<"The flexVector All values______________________________________________:"<<endl;
    cout<<"Range["<<range<<"] capacity "<<capacity<<"%"<<endl<<endl;;
    for(int i=0 ; i<range ; i++){

        cout<<"FlexVector["<<(LLowerLimit+i)<<"] value= "<<vector[i]<<endl;
    }
    cout<<"_________________________________________________________________________|"<<endl<<endl;
}

int IntIndVet::VerifyIndice(int indice){

    if((LLowerLimit<=indice) && (UUpperLimit>=indice)){
        return indice-LLowerLimit;
    }else{
        return -1;
    }
}

void IntIndVet::getASpecificValue(int indice){

    int V=VerifyIndice(indice);
    cout<<endl;

    if(V != -1){
        cout<<"The value in indice ["<<indice<<"] is: "<<vector[V]<<endl<<endl;        
    }else{
        cout<<"Incorrect indice!!! try again"<<endl<<endl;
    }

}
