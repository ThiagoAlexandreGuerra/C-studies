#include "./FindNumber_2.h"

#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <sstream>

using namespace std;


FindNumber_2::FindNumber_2(){

    Left=false;
    Right=false;
    FindExpoentInSecondNumber=false;
    dubleDot=false;
    Stop_Div=false;
    Stop_Expo=false;
    Stop_Mult=false;
    FirstNumber_isFulled=false;

    I=0;
    AmountOfMultiplications=0;
    NumberForResult=1;
    checkIfDubleDot=0;

    FirstNumber="";
    SecondNumber="";
    AuxExpoent="";
};
FindNumber_2::~FindNumber_2(){};

FindNumberFinalResult FindNumber_2::Get(sstringByUser stringByUser , int CurrentIndex , int LeftOrRight){
    return FuncFindNumber(stringByUser ,CurrentIndex, LeftOrRight );
}

float FindNumber_2::MultiplicationOfNumbersInStringType(string A ,string B){
    
    std::setlocale(LC_ALL, "C");
    bool IfAOk=false , IfBOk=false;
    float aux=1 , aux2=1 , multipliesResult;

    if(DoExistNumberInString(A)){IfAOk=true;}
    if(DoExistNumberInString(B)){IfBOk=true;}

    if(IfAOk && IfBOk){
        
        try {
            stringstream AA (A);
            stringstream BB (B);

            AA>>aux;
            BB>>aux2;

            multipliesResult=aux*aux2;
            return multipliesResult;
            
        } catch (const std::invalid_argument&) {
            cerr << "Erro: '" << A <<" ou " << B <<"' não é um número válido.\n";
            return 1;
        }

    }

    if (IfAOk){return std::stof(A);}
    if (IfBOk){return std::stof(B);}

    return 1;
    
}

float FindNumber_2::ExponetiationOfNumbersInStringType(string A ,string B){

    std::setlocale(LC_ALL, "C");
    bool IfAOk=false , IfBOk=false;
    float aux=1 , aux2=1 , ExponentiationResult;

    if(DoExistNumberInString(A)){IfAOk=true;}
    if(DoExistNumberInString(B)){IfBOk=true;}

    if(IfAOk && IfBOk){
        try {
            stringstream AA (A);
            stringstream BB (B);

            AA>>aux;
            BB>>aux2;

            ExponentiationResult=pow (aux, aux2);
            return ExponentiationResult;
            
        } catch (const std::invalid_argument&) {
            cerr << "Erro: '" << A <<" ou " << B <<"' não é um número válido.\n";
            return 1;
        }

    }

    if (IfAOk){return std::stof(A);}
    

    return 1;
    
}

float FindNumber_2::DivisionOfNumbersInStringType(string A ,string B){

    std::setlocale(LC_ALL, "C");
    bool IfAOk=false , IfBOk=false;
    float aux=1 , aux2=1 , DivisionResult;

    if(DoExistNumberInString(A)){IfAOk=true;}
    if(DoExistNumberInString(B)){IfBOk=true;}

    if(IfAOk && IfBOk){
        
        try {
            stringstream AA (A);
            stringstream BB (B);

            AA>>aux;
            BB>>aux2;

            DivisionResult=aux/aux2;

            return DivisionResult;
            
        } catch (const std::invalid_argument&) {
            cerr << "Erro: '" << A <<" ou " << B <<"' não é um número válido.\n";
            return 1;
        }

    }

    if (IfAOk){return std::stof(A);}
    if (IfBOk){return std::stof(B);}

    return 1;
    
}

bool FindNumber_2::FindTheSing_PlusOrMinus(bool OnlyVerification){
    return (stringFromUser.sstringg[I]=='+' || stringFromUser.sstringg[I]=='-');
}
bool FindNumber_2::FindTheSing_multiplie(bool OnlyVerification){
    
    if((stringFromUser.sstringg[I]=='*')){
        if(!OnlyVerification){
            if(Right && (I<stringFromUser.length-1)){I++;}
            if(Left && (I>0)){I--;}
        }
        AmountOfMultiplications++;

        return true;
        
    }else{
        return false;
    }
}

bool FindNumber_2::FindTheSing_Exponetiation(bool OnlyVerification){
    
   
    if(stringFromUser.sstringg[I]=='^'){
        if(!OnlyVerification){
            if(Right && (I<stringFromUser.length-1)){I++;}
            if(Left && (I>0)){I--;}
        }
        return true ;
    }else{
        return false;
    }
};
bool FindNumber_2::FindTheSing_Division(bool OnlyVerification){
    if(stringFromUser.sstringg[I]=='/'){
        if(!OnlyVerification){
            if(Right && (I<stringFromUser.length-1)){I++;}
            if(Left && (I>0)){I--;}
        }
        return true ;
    }else{
        return false;
    }
};

FindNumberFinalResult FindNumber_2::FuncFindNumber(sstringByUser stringByUser , int CurrentIndex , int LeftOrRight){

    cout<<"FuncFindNumber FindNumber_2.cpp____________________________________________________:"<<endl;
    cout<<endl<<"string by user: "<<stringByUser.sstringg<<"Length: "<<stringByUser.length<<endl;
    cout<<endl<<"current index: "<<CurrentIndex<<endl;
    cout<<endl<<"left or right: "<< LeftOrRight<<endl;
    cout<<endl<<"First Caracter: "<<stringByUser.sstringg[CurrentIndex]<<endl;
    cout<<"__________________________________________________________________________________||"<<endl<<endl;

    FindNumberFinalResult RESULT;
    stringFromUser=stringByUser;

    int checkIfDubleDot=0 ;
    bool FindDigiti=false , theSameNextOperation=false;;

    if(LeftOrRight==0){Left=true;}
    if(LeftOrRight==1){Right=true;}
    
    I=CurrentIndex;
    if(Left){
        
        for (I ; I>0 ; I--){
    
            ToCheckIfDoubleDot();
            
            if(FindTheSing_Division(false) && (!Stop_Div)){
                theSameNextOperation=false;
                FirstNumber_isFulled=false;
                CleanDobleDot();RealiseThe_DivisionOperation();     
            }

            if(FindTheSing_Exponetiation(false) && (!Stop_Expo)){
                theSameNextOperation=false;
                FirstNumber_isFulled=false;
                CleanDobleDot();RealiseThe_ExponetiationOperation(1);}

                if(FindTheSing_multiplie(theSameNextOperation) && (!Stop_Mult)){
                    theSameNextOperation=false;
                FirstNumber_isFulled=false;
                CleanDobleDot();
                RealiseThe_MultiplieOperation();
                if(IfItHasAnotherMultiplicationInNext()){Wating();theSameNextOperation=true;}
            }
            if(FindTheSing_PlusOrMinus(false)){CleanDobleDot();FirstNumber_IsEmpty();break;}
            
            if( (isdigit(stringByUser.sstringg[I])||(stringByUser.sstringg[I]=='.')) && !(dubleDot)  && SingNonConcat()  && !(FirstNumber_isFulled)){
                
                FirstNumber=stringByUser.sstringg[I]+FirstNumber;
               
            }
            if (DoExistNumberInString(FirstNumber) && BreakConcat() && theSameNextOperation){I--;FirstNumber_isFulled=true;Wating();}
            
        }
    
    }
    if(Right){
        

        for (I ; I< stringFromUser.length-1; I++){
            ToCheckIfDoubleDot();
            cout<<"For FuncFindNumber Begin_____________:"<<endl;
            cout<<"| StringFromUser.sstringg["<<I<<"] :"<<stringFromUser.sstringg[I]<<endl;
            cout<<"| Stop_Div: "<<Stop_Div<<endl;
            cout<<"| Stop_Mult: "<<Stop_Mult<<endl;
            cout<<"| Stop_Expo: "<<Stop_Expo<<endl;
            cout<<"| FirstNumber: "<<FirstNumber<<endl;
            cout<<"| SencondNumber: "<<SecondNumber<<endl;
            cout<<"| FirstNumber_isFulled: "<<FirstNumber_isFulled<<endl;
            cout<<"| theSameNextOperation: "<<theSameNextOperation<<endl;
            cout<<"|___________________________________||"<<endl<<endl;
            
            if(FindTheSing_Exponetiation(false) && (!Stop_Expo)){
                theSameNextOperation=false;
                FirstNumber_isFulled=false;
                CleanDobleDot();RealiseThe_ExponetiationOperation(1);}
            if(FindTheSing_multiplie(false)  && (!Stop_Mult)){
                theSameNextOperation=false;
                FirstNumber_isFulled=false;
                CleanDobleDot();RealiseThe_MultiplieOperation();
                if(IfItHasAnotherMultiplicationInNext()){Wating();theSameNextOperation=true;}
                // cout<<"Back to funcFindNumber from RealiseThe_MultiplieOperation_________________________________ : "<<endl<<endl;
                // cout<<"| theSameNextOperation: "<<theSameNextOperation<<endl;
                // cout<<"| IfItHasAnotherMultiplicationInNext: "<< IfItHasAnotherMultiplicationInNext()<<endl;
                // cout<<"| theSameNextOperation: "<<theSameNextOperation<<endl;
                // cout<<"| FirstNumber: "<<FirstNumber<<endl;
                // cout<<"| SecondNumber: "<<SecondNumber<<endl;
                // cout<<"|StringFromUser.sstringg["<<I<<"] :"<<stringFromUser.sstringg[I]<<endl;
                // cout<<"___________________________________________________________________________________________||"<<endl<<endl;              
            }
            if(FindTheSing_Division(false) && (!Stop_Div)){
                theSameNextOperation=false;
                FirstNumber_isFulled=false;
                CleanDobleDot();
                RealiseThe_DivisionOperation();
            }
            
            if(FindTheSing_PlusOrMinus(false)){CleanDobleDot();FirstNumber_IsEmpty();break;}
            if( (isdigit(stringByUser.sstringg[I])||(stringByUser.sstringg[I]=='.')) && !(dubleDot)  && SingNonConcat() && !(FirstNumber_isFulled)){
                
                FirstNumber= FirstNumber+ stringByUser.sstringg[I];
                
                
            }
            cout<<"For FuncFindNumber End_____________:"<<endl;
            cout<<"| Stop_Div: "<<Stop_Div<<endl;
            cout<<"| Stop_Mult: "<<Stop_Mult<<endl;
            cout<<"| Stop_Expo: "<<Stop_Expo<<endl;
            cout<<"| FirstNumber: "<<FirstNumber<<endl;
            cout<<"| SencondNumber: "<<SecondNumber<<endl;
            cout<<"| FirstNumber_isFulled: "<<FirstNumber_isFulled<<endl;
            cout<<"| DoExistNumberInString(FirstNumber): "<<DoExistNumberInString(FirstNumber)<<endl;
            cout<<"| BreakConcat(): "<<BreakConcat()<<endl;
            cout<<"| theSameNextOperation: "<<theSameNextOperation<<endl;
            cout<<"| StringFromUser.sstringg["<<I<<"] :"<<stringFromUser.sstringg[I]<<endl;
            cout<<"| NumberForResult: "<<NumberForResult<<endl;
            cout<<"| FindTheSing_PlusOrMinus(false): "<<FindTheSing_PlusOrMinus(false)<<endl;
            cout<<"|___________________________________||"<<endl<<endl;
            if (DoExistNumberInString(FirstNumber) && BreakConcat() && theSameNextOperation){I++;FirstNumber_isFulled=true;Wating();}

            
        }
        
    }
    if(IfItHasValueButNoOperation()){CleanDobleDot();FirstNumber_IsEmpty();}
    End();

    cout<<"NumberForResult: "<<NumberForResult<<endl;
    RESULT.NewIndex=I==-1?0:I;
    RESULT.result=NumberForResult;

    cout<<"RESULT.NewIndex: "<<RESULT.NewIndex<<endl;
    cout<<"RESULT.result: "<<RESULT.result<<endl;
    return RESULT;
};
void FindNumber_2::FirstNumber_IsEmpty(){
    bool NumberContentDigit=false;
    for(int k=0 ; k<FirstNumber.size() ; k++){
        if(isdigit(FirstNumber[k])){NumberContentDigit=true;}
    }
    if( (AmountOfMultiplications==0 ) && (NumberContentDigit) ){NumberForResult=MultiplicationOfNumbersInStringType(FirstNumber, "");}
    
}

bool FindNumber_2::DoExistNumberInString(string NumberInString){

    if(NumberInString.empty()){return false;}
    
    for(int k=0 ; k<NumberInString.size() ; k++){
        if(isdigit(NumberInString[k])){return true;}
    }
    return false;
}

void FindNumber_2::RealiseThe_MultiplieOperation(){
    cout<<"| stringFromUser.sstringg["<<I<<"]: "<<stringFromUser.sstringg[I]<<endl;
    
    AchiveTheNexTNumber();
    cout<<"RealiseThe_MultiplieOperation_______________________________________________________:"<<endl<<endl;
    cout<<"| IfExistSingDivision: "<<IfExistSingDivision()<<endl;
    cout<<"| stringFromUser.sstringg["<<I<<"]: "<<stringFromUser.sstringg[I]<<endl;
    if(AmountOfMultiplications==1){NumberForResult=1;}
    if(IfExistSingDivision() && !FindExpoentInSecondNumber){
        cout<<"| FirstNumber: "<<FirstNumber<<endl;
        cout<<"| SecondNumber: "<<SecondNumber<<endl;
        FirstNumber=to_string(MultiplicationOfNumbersInStringType(FirstNumber,SecondNumber));
        SecondNumber="";
        cout<<"| FirstNumber After: "<<FirstNumber<<endl;
        cout<<"| SecondNumber After: "<<SecondNumber<<endl;
        cout<<"| :"<<endl;
        if(Right){I++;}
        if(Left){I--;}
        RealiseThe_DivisionOperation();

    }else if(FindExpoentInSecondNumber){
        cout<<"| FirstNumber: "<<FirstNumber<<endl;
        cout<<"| SecondNumber: "<<SecondNumber<<endl;
        cout<<"| AuxExpoent: "<<AuxExpoent<<endl;
        if(Left){NumberForResult=ExponetiationOfNumbersInStringType(AuxExpoent , SecondNumber)*NumberForResult;}
        if(Right){NumberForResult=ExponetiationOfNumbersInStringType(SecondNumber , AuxExpoent)*NumberForResult;}
        NumberForResult=MultiplicationOfNumbersInStringType(FirstNumber,"")*NumberForResult;
        
        FindExpoentInSecondNumber=false;
        FirstNumber="";
        AuxExpoent="";
        SecondNumber="";
        cout<<"| stringFromUser.sstringg["<<I<<"]: "<<stringFromUser.sstringg[I]<<endl;

        if(IfExistSingDivision()){
            FirstNumber=to_string(NumberForResult);
            NumberForResult=1;
            if(Left){I--;}
            if(Right){I++;}
            cout<<"| FirstNumber: "<<FirstNumber<<endl;
            cout<<"| stringFromUser.sstringg["<<I<<"]: "<<stringFromUser.sstringg[I]<<endl;
            FindExpoentInSecondNumber=false;

            RealiseThe_DivisionOperation();
        }
    }else{
        
        NumberForResult=MultiplicationOfNumbersInStringType(FirstNumber , SecondNumber)*NumberForResult;
        FirstNumber="";
        SecondNumber="";
    }
    
    cout<<"|__________________________________________________________________________________||"<<endl<<endl;
    Stop_Div=false;
    Stop_Expo=false;
    Stop_Mult=false;
}

void FindNumber_2::RealiseThe_ExponetiationOperation(int WhatIsNumber){

    cout<<"RealiseThe_ExponetiationOperation_____________________________________________________:"<<endl;
    cout<<"| FirstNumber: "<<FirstNumber<<endl;
    cout<<"| SecondNumber: "<<SecondNumber<<endl;
    cout<<"| StringFromUser.sstring["<<I<<"] :"<<stringFromUser.sstringg[I]<<endl;

    if(WhatIsNumber==1){
        AchiveTheNexTNumber();
        cout<<"| FirstNumber After AchiveNextNumber: "<<FirstNumber<<endl;
        cout<<"| SecondNumber After AchiveNextNumber: "<<SecondNumber<<endl;
        cout<<"| IfExistSingDivision(): "<<IfExistSingDivision()<<endl;
        if(IfExistSingDivision()){
           
            string SaveLeft="";
            if(Right){SaveLeft=to_string(ExponetiationOfNumbersInStringType(FirstNumber, SecondNumber));}
            if(Left){SaveLeft=to_string(ExponetiationOfNumbersInStringType(SecondNumber, FirstNumber));}
            
            FirstNumber=SaveLeft;
            SecondNumber="";
            cout<<"| SaveLeft: "<<SaveLeft<<endl;
            cout<<"| SecondNumber: "<<SecondNumber<<endl;
            cout<<"| StringFromUser.sstring["<<I<<"] :"<<stringFromUser.sstringg[I]<<endl;
            if(Left){I--;}
            if(Right){I++;}
            cout<<"| StringFromUser.sstring after upadate index["<<I<<"] :"<<stringFromUser.sstringg[I]<<endl;
            cout<<"| Call to RealiseThe_DivisionOperation-------> "<<endl;
            cout<<"|________________________________________________________________________________________:"<<endl<<endl;
            RealiseThe_DivisionOperation();

        }else{
            
            if(Right){NumberForResult=ExponetiationOfNumbersInStringType(FirstNumber, SecondNumber)*NumberForResult;}
            if(Left){NumberForResult=ExponetiationOfNumbersInStringType(SecondNumber, FirstNumber)*NumberForResult;}
            
            SecondNumber="";
            FirstNumber="";
        }
    }
    if(WhatIsNumber==2){
        
        FindExpoentInSecondNumber=true;        
        AchiveTheNexTNumber();
        
    }

    Stop_Div=false;
    Stop_Expo=false;
    Stop_Mult=false;
}

void FindNumber_2::RealiseThe_DivisionOperation(){
    cout<<"RealiseThe_DivisionOperation______________________________________________________:"<<endl<<endl;
    cout<<"|FirstNumber before AchiveTheNexTNumber: "<<FirstNumber<<endl;
    cout<<"|SecondNumber before AchiveTheNexTNumber: "<<SecondNumber<<endl;
    AchiveTheNexTNumber();
    cout<<"| FirstNumber: "<<FirstNumber<<endl;
    cout<<"| SecondNumber: "<<SecondNumber<<endl;
    cout<<"| AuxExpoent: "<<AuxExpoent<<endl;
    cout<<"| FindExpoentInSecondNumber :"<<FindExpoentInSecondNumber<<endl;
    cout<<"| :"<<endl;
    cout<<"|________________________________________________________________________________||"<<endl<<endl;
    string AuxDivision="";
    
    if(FindExpoentInSecondNumber){
        
        if(Left){AuxDivision=to_string(ExponetiationOfNumbersInStringType(AuxExpoent , SecondNumber));}
        if(Right){AuxDivision=to_string(ExponetiationOfNumbersInStringType(SecondNumber , AuxExpoent));}
        if(Right){NumberForResult=DivisionOfNumbersInStringType(FirstNumber , AuxDivision)*NumberForResult;}
        if(Left){NumberForResult=DivisionOfNumbersInStringType(AuxDivision , FirstNumber)*NumberForResult;} 
        cout<<"| FindExpoentInSecondNumber !!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        FindExpoentInSecondNumber=false;
        AuxExpoent="";
        AuxDivision="";
        FirstNumber="";
        SecondNumber="";

    }else{
        cout<<"| else option!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
        cout<<"| FirstNumber: "<<FirstNumber<<endl;
        cout<<"| SecondNumber: "<<SecondNumber<<endl;
        if(Right){NumberForResult=DivisionOfNumbersInStringType(FirstNumber , SecondNumber)*NumberForResult;}
        if(Left){NumberForResult=DivisionOfNumbersInStringType(SecondNumber , FirstNumber)*NumberForResult;} 
        cout<<"| NumberForResult: "<<NumberForResult<<endl;
        
    }
    
    FirstNumber="";
    SecondNumber="";
    Stop_Div=false;
    Stop_Expo=false;
    Stop_Mult=false;

}
void FindNumber_2::AchiveTheNexTNumber(){
    
    
    if(Left){
        
        if(FindExpoentInSecondNumber){
            for(I; I>0 ; I--){
                if(FindTheSing_PlusOrMinus(true)||FindTheSing_Division(true)||FindTheSing_multiplie(true)||FindTheSing_Exponetiation(true)){break;}
                if(isdigit(stringFromUser.sstringg[I]) || (stringFromUser.sstringg[I]=='.') ){AuxExpoent=stringFromUser.sstringg[I]+AuxExpoent;}
                ToCheckIfDoubleDot();
            }
            CleanDobleDot();
        }else{
            
            for(I; I>0 ; I--){
                if(FindTheSing_PlusOrMinus(true)||FindTheSing_Division(true)||FindTheSing_multiplie(true)){break;}

                if(FindTheSing_Exponetiation(false)){RealiseThe_ExponetiationOperation(2);break;}
                
                if(isdigit(stringFromUser.sstringg[I]) || (stringFromUser.sstringg[I]=='.')){SecondNumber=stringFromUser.sstringg[I]+SecondNumber;}
                ToCheckIfDoubleDot();
            }
            CleanDobleDot();
        }
    }
    
    if(Right){

        if(FindExpoentInSecondNumber){
            
            for(I ; I< stringFromUser.length-1; I++){
                if(FindTheSing_PlusOrMinus(true)||FindTheSing_Division(true)||FindTheSing_multiplie(true)||FindTheSing_Exponetiation(true)){break;}
                if(isdigit(stringFromUser.sstringg[I]) || (stringFromUser.sstringg[I]=='.') ){AuxExpoent=AuxExpoent+ stringFromUser.sstringg[I];}

                ToCheckIfDoubleDot();
            }
            CleanDobleDot();
        }else{

            for(I ; I< stringFromUser.length-1; I++){

                if(FindTheSing_PlusOrMinus(true)||FindTheSing_Division(true)||FindTheSing_multiplie(true)){break;}
                if(FindTheSing_Exponetiation(false)){RealiseThe_ExponetiationOperation(2);break;}
                if(isdigit(stringFromUser.sstringg[I]) || (stringFromUser.sstringg[I]=='.')){SecondNumber=SecondNumber + stringFromUser.sstringg[I];}
                ToCheckIfDoubleDot();
            }
            CleanDobleDot();
        }
        
    }
    
}
        
void FindNumber_2::ToCheckIfDoubleDot(){
    if(stringFromUser.sstringg[I]=='.'){checkIfDubleDot++;}
    if(checkIfDubleDot>1){
        cerr<<"You wirited a double dot ,it is invalid, make sure that your function is correct and try again!!!"<<endl;
        exit(-1);
    }
}

void FindNumber_2::CleanDobleDot(){
    if(dubleDot){

        checkIfDubleDot=0;
        dubleDot=false;
    }
}

bool FindNumber_2::SingNonConcat(){
    if(FindTheSing_Division(true)||FindTheSing_multiplie(true)||FindTheSing_Exponetiation(true)){return false;}
    return true;

}

bool FindNumber_2::IfExistSingDivision(){
    if(Left){

        int K= I;
        for(K ; K>0 ; K--){
            if(isdigit(stringFromUser.sstringg[K])||FindTheSing_multiplie(true)||FindTheSing_Exponetiation(true)||FindTheSing_PlusOrMinus(true)){return false;}
            if(FindTheSing_Division(true)){return true;}
        }
    }
    if(Right){

        int K= I;
        
        for(K ; K<stringFromUser.length; K++){
            if(isdigit(stringFromUser.sstringg[K])||FindTheSing_multiplie(true)||FindTheSing_Exponetiation(true)||FindTheSing_PlusOrMinus(true)){return false;}
            if(FindTheSing_Division(true)){return true;}
        }
    }
}

bool FindNumber_2::IfExistSingExponentiation(){
    if(Left){

        int K= I;
        for(K ; K>0 ; K--){
            if(isdigit(stringFromUser.sstringg[K])||FindTheSing_multiplie(true)||FindTheSing_Division(true)||FindTheSing_PlusOrMinus(true)){return false;}
            if(FindTheSing_Exponetiation(true)){return true;}
        }
    }
    if(Right){

        int K= I;
        
        for(K ; K<stringFromUser.length; K++){
            if(isdigit(stringFromUser.sstringg[K])||FindTheSing_multiplie(true)||FindTheSing_Division(true)||FindTheSing_PlusOrMinus(true)){return false;}
            if(FindTheSing_Exponetiation(true)){return true;}
        }
    }
}

bool FindNumber_2::IfItHasValueButNoOperation(){

    if(((I)==0)||(I==stringFromUser.length-1) 
        && (stringFromUser.sstringg[0]==' ' || stringFromUser.sstringg[stringFromUser.length-1]==' ' )
        && (NumberForResult==1)
    ){
        return true;

    }
    return false;
}

bool FindNumber_2::IfItHasAnotherMultiplicationInNext(){
    if(stringFromUser.sstringg[I]=='*'){
        return true;
    }
    return false;
}

void FindNumber_2::Wating(){
    cout<<"Wating_________________________________________________________________________:"<<endl;
    cout<<"| FirstNumber_isFulled && IfExistSingExponentiation() : "<<(FirstNumber_isFulled && IfExistSingExponentiation())<<endl;
    cout<<"| FirstNumber_isFulled && IfExistSingDivision() : "<<(FirstNumber_isFulled && IfExistSingDivision())<<endl;
    cout<<"| StringFromUser.sstringg["<<I<<"] before update index:"<<stringFromUser.sstringg[I]<<endl;
    if(!FirstNumber_isFulled){W=I;}
    
    if(FirstNumber_isFulled && IfExistSingExponentiation()){
        Stop_Expo=false;
        Stop_Div=true;
        Stop_Mult=true;
        cout<<"| index Global: "<<I<<endl;
        if(Left){I++;}
        if(Right){I--;
            
            cout<<"| Update done!!!!!!!!!!!! I: "<<I<<endl;
        }
        cout<<"|Index Global: "<<I<<endl;

    }else if(FirstNumber_isFulled && IfExistSingDivision()){
        Stop_Div=false;
        Stop_Expo=true;
        Stop_Mult=true;
        if(left){I++;}
        if(Right){I--;}
    }else if(stringFromUser.sstringg[W]=='*'){
        Stop_Div=true;
        Stop_Expo=true;
        Stop_Mult=true;

        if(FirstNumber_isFulled){ Stop_Mult=false;}
        if(left){I++;}
        if(Right){I--;}
    }
    cout<<"| I: "<<I<<" and W: "<<W<<endl;
    cout<<"| Stop_Div: "<<Stop_Div<<endl;
    cout<<"| Stop_Mult: "<<Stop_Mult<<endl;
    cout<<"| Stop_Expo: "<<Stop_Expo<<endl;
    cout<<"| FirstNumber: "<<FirstNumber<<endl;
    cout<<"| SencondNumber: "<<SecondNumber<<endl;
    cout<<"| FirstNumber_isFulled: "<<FirstNumber_isFulled<<endl;
    cout<<"| DoExistNumberInString(FirstNumber): "<<DoExistNumberInString(FirstNumber)<<endl;
    cout<<"| BreakConcat(): "<<BreakConcat()<<endl;
    cout<<"| StringFromUser.sstringg["<<I<<"] :"<<stringFromUser.sstringg[I]<<endl;
    cout<<"|____________________________________________________________________________||"<<endl<<endl;
}

bool FindNumber_2::BreakConcat(){

    int k=0;

    if(Left){k=I>0?I-1:I;}
    if(Right){k=I<stringFromUser.length-1?I+1:I;}

    if((stringFromUser.sstringg[k]=='+') || (stringFromUser.sstringg[k]=='-') || (stringFromUser.sstringg[k]=='*')
        || (stringFromUser.sstringg[k]=='/') || (stringFromUser.sstringg[k]=='^') || (stringFromUser.sstringg[k]==' ')
    ){
        return true;
    }

    return false;
}

void FindNumber_2::End(){

    if(DoExistNumberInString(FirstNumber)){
        NumberForResult=MultiplicationOfNumbersInStringType(FirstNumber,"")* NumberForResult;
    }
}