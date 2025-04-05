#ifndef FINDNUMBER_H
#define FINDNUMBER_H

#include <string>
#include <iostream>

using namespace std;

typedef struct 
{
   int UpdateIndex=0;
   string StringResult="";
   bool whateverBoolTest=false;

} StringResultAndUpdateIndex;


typedef struct{

    int length=0;
    string sstringg="";
}sstringByUser;

typedef struct{

    bool ifSingDivision=false;

}DataForFindExpoentForFindNumberLeft;

typedef struct{

    bool findMultiplication=false ;
    bool FindExponentiation=false ;
    bool FindTheNextNumberAndStop=false ;
    bool AchiveNumber=false;
    bool dubleDot=false ;
    bool dubleDotForMultNumber=false ;
    bool FindDivision=false;
    
    float result=0;

    int newIndex=0;

    StringResultAndUpdateIndex AuxExponentiation ;
    StringResultAndUpdateIndex NumberForDivision;

    DataForFindExpoentForFindNumberLeft singDivision;
    string FirstNumber;
    string SecondNumber;


}FindNumberStateFunc; 

typedef struct{

    float result=0;
    int NewIndex=0;

}FindNumberFinalResult;

class FindNumber{

    private:

        void FindNumberPrint(bool Rigth , bool Left , string Number , string NumberForMult ,string Divisor , string Expoent , bool dubleDot, bool findMultiplication, bool FindExponentiation, bool AchiveNumber , bool dubleDotForMultNumber , bool FindDivision , bool FindDivisionFromExponetiation , float numberNumber, int I );
        

        float MultiplicationOfNumbersInStringType(string A ,string B);
        float ExponetiationOfNumbersInStringType(string A ,string B);
        float DivisionOfNumbersInStringType(string A ,string B);

        FindNumberFinalResult FuncFindNumber(sstringByUser stringByUser , int CurrentIndex , int LeftOrRight);

        StringResultAndUpdateIndex FindExpoentForFindNumberLeftOrRight (int currentIndex , sstringByUser s, int LeftOrRight );
        StringResultAndUpdateIndex FindDividend(int currentIndex , sstringByUser s , int LeftOrRight );

        FindNumberStateFunc FuncFindExponentiation(int AmountOfMultiplications , int currentIndex ,int LeftOrRight, sstringByUser stringByUser, string Number , string NumberForMult );
        FindNumberStateFunc FindDivisionFunc(bool FindDivision , bool FindDivisionFromExponetiation , int AmountOfMultiplications , sstringByUser stringByUser, int currentIndex,int LeftOrRight, string divisor, string Number, string NumberForMult, float numberNumber);

        int  I=0 , checkIfDubleDot=0 , checkIfDubleDotForMultNumber=0 , AmountOfMultiplications=0;

        string Number="" , Expoent="" , NumberForMult="", divisor="" ;

        StringResultAndUpdateIndex AuxExponentiation , NumberForDivision;

        FindNumberStateFunc FindExponentiationResult , FindDivisionResult;

        bool findMultiplication=false , FindExponentiation=false , FindTheNextNumberAndStop=false , AchiveNumber=false;
        bool dubleDot=false , dubleDotForMultNumber=false , FindDivision=false , FindDivisionFromExponetiation=false;
        bool Right=false , Left=false;
        float numberNumber=1;

    public:
        FindNumber(sstringByUser stringByUser , int CurrentIndex , int LeftOrRight);
        FindNumber();
        FindNumberFinalResult Get(sstringByUser stringByUser , int CurrentIndex , int LeftOrRight);



};

#endif