#include "IntIndVet.h" 
#include <iostream>

using namespace std;

int main(){
    
    int LowerLimit=0 , UpperLimit=0 , indice=0;
    bool CONTINUE;

    cout<<"Welcome to the FlexVector Program_______________________________________:"<<endl<<endl;
    cout<<"Wirite the lower limit and the upper limit in this order,"<<endl;
    cout<<"Ensure that the lower limit is smaller than the upper limit: " << endl;

    cout<<"Lower limit: ";
    cin>>LowerLimit;
    cout<<endl;
    cout<<"Upper limit: ";
    cin>>UpperLimit;

    IntIndVet vet(LowerLimit,UpperLimit);
    vet.setValues();
    vet.getAllValues();

    while (CONTINUE)
    {   

        cout<<endl;
        cout<<"here you can choise a specific indice of FlexVector, write a indice: ";
        cin>>indice;
        vet.getASpecificValue(indice);

        cout<<"press 1 for continue or 0 for exist: ";
        cin>>CONTINUE;
        cout<<endl;
    }
    


    
}