#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cstdlib>


using namespace std;

class Vector{

    private:
        float *vector=nullptr; 
        float capacity=0;
        int AmountOfValues=0;
        int Length=0;
        void updateInCapacity();

    public:
        Vector();
        Vector(int vectorLength);
        ~Vector();

        void setVectorValues();
        void getVectorValues();
};


#endif