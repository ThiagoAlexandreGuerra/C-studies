#ifndef FINDNUMBER_2_H
#define FINDNUMBER_2_H

#include <string>
#include <iostream>

using namespace std;

typedef struct 
{
   int UpdateIndex;
   string StringResult;
   bool whateverBoolTest;

} StringResultAndUpdateIndex;

typedef struct{

    int length;
    string sstringg;
}sstringByUser;

typedef struct{

    bool ifSingDivision;

}DataForFindExpoentForFindNumberLeft;

typedef struct{

    bool findMultiplication ;
    bool FindExponentiation ;
    bool FindTheNextNumberAndStop ;
    bool AchiveNumber;
    bool dubleDot ;
    bool dubleDotForMultNumber;
    bool FindDivision;
    
    float result;

    int newIndex;

    StringResultAndUpdateIndex AuxExponentiation ;
    StringResultAndUpdateIndex NumberForDivision;

    DataForFindExpoentForFindNumberLeft singDivision;
    string FirstNumber;
    string SecondNumber;


}FindNumberStateFunc; 

typedef struct{

    float result;
    int NewIndex;

}FindNumberFinalResult;


class FindNumber_2
{
    private:

        bool FindTheSing_PlusOrMinus(bool OnlyVerification);
        bool FindTheSing_multiplie(bool OnlyVerification);
        bool FindTheSing_Exponetiation(bool OnlyVerification);
        bool FindTheSing_Division(bool OnlyVerification);
        bool DoExistNumberInString(string NumberInString);
        bool SingNonConcat();
        bool IfExistSingDivision();
        bool IfExistSingExponentiation();
        bool IfItHasValueButNoOperation();
        bool IfItHasAnotherMultiplicationInNext();
        bool BreakConcat();
        
        float MultiplicationOfNumbersInStringType(string A ,string B);
        float ExponetiationOfNumbersInStringType(string A ,string B);
        float DivisionOfNumbersInStringType(string A ,string B);
        
        void FirstNumber_IsEmpty();
        void RealiseThe_MultiplieOperation();
        void RealiseThe_ExponetiationOperation(int WhatIsNumber);
        void RealiseThe_DivisionOperation();
        void AchiveTheNexTNumber();
        void CleanDobleDot();
        void ToCheckIfDoubleDot();
        void Wating();
        void End();

        bool Left, Right ,FindExpoentInSecondNumber, dubleDot , Stop_Mult , Stop_Expo , Stop_Div , FirstNumber_isFulled;

        int I,W, AmountOfMultiplications ,checkIfDubleDot;

        float NumberForResult ;

        string FirstNumber , SecondNumber , AuxExpoent;

        sstringByUser stringFromUser;


        FindNumberFinalResult FuncFindNumber(sstringByUser stringByUser , int CurrentIndex , int LeftOrRight);


    public:
        FindNumberFinalResult Get(sstringByUser stringByUser , int CurrentIndex , int LeftOrRight);
        FindNumber_2();
        ~FindNumber_2();
};




#endif