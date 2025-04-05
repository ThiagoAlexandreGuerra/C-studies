#ifndef INTINDVET_H
#define INTINDVET_H

#include <iostream>

class IntIndVet{

    private:
        
        int* vector=nullptr;

        int LLowerLimit=0;
        int UUpperLimit=0;
        float range=0;
        float occupy=0;
        float capacity=0;
        
        int VerifyIndice(int indice);

    public:
        IntIndVet(int LowerLimit , int UpperLimit);
        ~IntIndVet();


        void UpdateCapacity();
        void setValues();
        void getAllValues();
        void getASpecificValue(int indice);

};

#endif