#include <iostream>
#include "Triangle.h"
#include <cstdlib> 

using namespace std;

void Triangle::ClearTerminal(){

    system("CLS");

}

void Triangle::setSides(){

    ClearTerminal();

    cout<<"Wirite the sides of triangle"<<endl;

    cout<<"side A: ";
    cin>>A;
    cout<<endl;
    cout<<"side B: ";
    cin>>B;
    cout<<endl;
    cout<<"side C: ";
    cin>>C;
    cout<<endl;

}

int Triangle::TriangleType(){

    if((A==B)&&(A==C)){
        cout<<"is equilatero"<<endl;
        return 1;
    }else if((A==B)||(A==C)||(B==C)){
        cout<<"is isoceles"<<endl;
        return 2;
    }else{
        cout<<"is escaleno"<<endl;
        return 3;
    }
}

bool Triangle::Istriangle(){

    return (A + B > C) && (A + C > B) && (B + C > A);
}    

