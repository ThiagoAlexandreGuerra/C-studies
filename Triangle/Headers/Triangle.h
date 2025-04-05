#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <iostream>


using namespace std;

class Triangle{

    private:

        float A=0 , B=0 , C=0;
        bool IsTriangle=false;
        void ClearTerminal();

    public:
        void setSides();
        bool Istriangle();     
        int TriangleType();

};


#endif