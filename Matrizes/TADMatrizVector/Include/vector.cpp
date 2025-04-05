#include "vector.h"
#include <iostream>

using namespace std;

Vector::Vector(){

    Length=10;
    vector = new float[10]();
}

Vector::Vector(int VectorLength){

    Length=VectorLength;
    vector = new float[VectorLength]();
}

Vector::~Vector(){
    delete[] vector;
}
void Vector::updateInCapacity(){

    capacity=Length/AmountOfValues;
    
}
void Vector::setVectorValues(){

    bool CONTINUE= true;
    float Value=0;
    int i=0;

    while (CONTINUE)
    {
        updateInCapacity();
        cout<<"wirite the values for your vector with current capacity: "<<capacity<<endl;

        cout<<"value please: ";
        cin>>Value;
        vector[i]=Value;

        AmountOfValues++;
        i++;
        cout<<"If you finish press 0 for continue press 1: ";
        cin>>CONTINUE;
        cout<<endl;

    }
    
}

void Vector::getVectorValues(){

    cout<<"Vector______________________________________________:"<<endl;
    for(int i=0; i<Length ; i++){

        cout<<"Position ["<<i<<"]"<<" value: "<<vector[i]<<endl;
    }
    cout<<"____________________________________________________|"<<endl;

}
