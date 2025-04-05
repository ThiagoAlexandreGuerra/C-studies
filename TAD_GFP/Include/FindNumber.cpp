#include "./FindNumber.h"

#include <iostream>
#include <cmath>
#include <string>
#include <locale>
#include <sstream>

using namespace std;

FindNumber::FindNumber(){};

float FindNumber::MultiplicationOfNumbersInStringType(string A ,string B){

    
    std::setlocale(LC_ALL, "C");
    bool IfAOk=false , IfBOk=false;
    float aux=1 , aux2=1 , multipliesResult;

    if(!A.empty()){IfAOk=true;}
    if(!B.empty()){IfBOk=true;}

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

float FindNumber::ExponetiationOfNumbersInStringType(string A ,string B){

    
    std::setlocale(LC_ALL, "C");
    bool IfAOk=false , IfBOk=false;
    float aux=1 , aux2=1 , ExponentiationResult;

    if(!A.empty()){IfAOk=true;}
    if(!B.empty()){IfBOk=true;}

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

float FindNumber::DivisionOfNumbersInStringType(string A ,string B){

    
    std::setlocale(LC_ALL, "C");
    bool IfAOk=false , IfBOk=false;
    float aux=1 , aux2=1 , DivisionResult;

    if(!A.empty()){IfAOk=true;}
    if(!B.empty()){IfBOk=true;}

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

StringResultAndUpdateIndex FindNumber::FindExpoentForFindNumberLeftOrRight (int currentIndex , sstringByUser s, int LeftOrRight ){

    bool AchiveNumber=false , Left=false , Right=false;
    StringResultAndUpdateIndex numForExponentiation;
    
    
    if(LeftOrRight==0){Left=true;}
    if(LeftOrRight==1){Right=true;}
   
    if(Left){
        
        int I=currentIndex>0?currentIndex-1:currentIndex;
        for(I; I>0 ; I--){
            
            if((s.sstringg[I]=='+')||(s.sstringg[I]=='-')||(s.sstringg[I]=='*')){break;}


        if(isdigit(s.sstringg[I])){AchiveNumber=true;}

        if(AchiveNumber){
            
            if((s.sstringg[I]=='/')){
                numForExponentiation.whateverBoolTest=true; 
                numForExponentiation.UpdateIndex=I;
                break;
            }
            if((s.sstringg[I]==' ')||(s.sstringg[I]=='+')||(s.sstringg[I]=='-')||(s.sstringg[I]=='*') ){
                numForExponentiation.UpdateIndex=I;
                break;
            }
            numForExponentiation.StringResult=s.sstringg[I]+numForExponentiation.StringResult;

        }
        }
       

        return numForExponentiation;

    }

    if(Right){
        int I=currentIndex<s.length?currentIndex+1:currentIndex;

        for(I; I<s.length ; I++){
            
        if((s.sstringg[I]=='+')||(s.sstringg[I]=='-')||(s.sstringg[I]=='*')){break;}

        
        if(isdigit(s.sstringg[I])){AchiveNumber=true;}
        
        if(AchiveNumber){
            
            if((s.sstringg[I]=='/')){
                numForExponentiation.whateverBoolTest=true; 
                numForExponentiation.UpdateIndex=I;
                break;
            }
            if((s.sstringg[I]==' ')||(s.sstringg[I]=='+')||(s.sstringg[I]=='-')||(s.sstringg[I]=='*') ){
                numForExponentiation.UpdateIndex=I;
                break;
            }
            numForExponentiation.StringResult=numForExponentiation.StringResult + s.sstringg[I];
            
        }
        }

        return numForExponentiation;
        cout<<"FindExpoentForFindNumberLeftOrRight NumForExponentiation: "<<numForExponentiation.StringResult<<endl;
    }
    
    return numForExponentiation;
   
}

StringResultAndUpdateIndex FindNumber::FindDividend(int currentIndex , sstringByUser s , int LeftOrRight ){

    bool AchiveNumber=false , Left=false , Right=false;
    StringResultAndUpdateIndex numForExponentiation;

    if(LeftOrRight==0){Left=true;}
    if(LeftOrRight==1){Right=true;}

    if(Left){
        int I=currentIndex>0?currentIndex-1:currentIndex;

        for(I; I>0 ; I--){
            
            if((s.sstringg[I]=='^')){
                numForExponentiation.whateverBoolTest=true;
                numForExponentiation.UpdateIndex=I;
                break;
            }
            
            if((s.sstringg[I]=='+')||(s.sstringg[I]=='-')||(s.sstringg[I]=='*')){break;}
            
            
            if(isdigit(s.sstringg[I])){AchiveNumber=true;}
            
            if(AchiveNumber){
                numForExponentiation.StringResult=s.sstringg[I]+numForExponentiation.StringResult;
                if((s.sstringg[I]==' ')||(s.sstringg[I]=='+')||(s.sstringg[I]=='-')||(s.sstringg[I]=='*')||(s.sstringg[I]=='/')){
                    numForExponentiation.UpdateIndex=I;
                    break;
                }
                
            }
        }
        return numForExponentiation;
    }
    if(Right){

        int I=currentIndex<s.length?currentIndex+1:currentIndex;
        
        for(I; I<s.length ; I++){
            
            if((s.sstringg[I]=='^')){
                numForExponentiation.whateverBoolTest=true;
                numForExponentiation.UpdateIndex=I;
                break;
            }
            
            if((s.sstringg[I]=='+')||(s.sstringg[I]=='-')||(s.sstringg[I]=='*')){break;}
            
            
            if(isdigit(s.sstringg[I])){AchiveNumber=true;}
            
            if(AchiveNumber){
                
                if((s.sstringg[I]==' ')||(s.sstringg[I]=='+')||(s.sstringg[I]=='-')||(s.sstringg[I]=='*')||(s.sstringg[I]=='/')){
                    numForExponentiation.UpdateIndex=I;
                    break;
                }
                numForExponentiation.StringResult=numForExponentiation.StringResult + s.sstringg[I];
                
            }
        }

        cout<<"FindDividend numForExponentiation: "<<numForExponentiation.StringResult<<endl;

        return numForExponentiation;
    }


    return numForExponentiation;
}


FindNumberStateFunc FindNumber::FuncFindExponentiation(int AmountOfMultiplications , int currentIndex ,int LeftOrRight, sstringByUser stringByUser, string Number , string NumberForMult ){

    StringResultAndUpdateIndex AuxExponentiation;
    FindNumberStateFunc state;
    bool Left=false, Right=false;
    

    if(LeftOrRight==0){Left=true;}
    if(LeftOrRight==1){Right=true;}

    if((AmountOfMultiplications%2 == 0) ){
        AuxExponentiation=FindExpoentForFindNumberLeftOrRight(currentIndex, stringByUser , LeftOrRight);

        if(Left){state.result=ExponetiationOfNumbersInStringType(AuxExponentiation.StringResult , Number);}
        if(Right){state.result=ExponetiationOfNumbersInStringType(Number, AuxExponentiation.StringResult );}
        cout<<"FuncFindExponentiation state.result: "<<state.result<<endl;
        state.newIndex= AuxExponentiation.UpdateIndex;
        state.FindExponentiation=false;
        state.singDivision.ifSingDivision=AuxExponentiation.whateverBoolTest;
        state.FirstNumber="";
        state.SecondNumber=NumberForMult;

    }else{

        AuxExponentiation=FindExpoentForFindNumberLeftOrRight(currentIndex, stringByUser , LeftOrRight);
        cout<<"FuncFindExponentiation AuxExponentiation.StringResult: "<<AuxExponentiation.StringResult<<endl;
        cout<<"FuncFindExponentiation Number: "<<NumberForMult<<endl;
        if(Left){state.result=ExponetiationOfNumbersInStringType(AuxExponentiation.StringResult ,NumberForMult);}
        if(Right){state.result=ExponetiationOfNumbersInStringType(NumberForMult, AuxExponentiation.StringResult );}
        cout<<"FuncFindExponentiation state.result: "<<state.result<<endl;
        
        state.newIndex= AuxExponentiation.UpdateIndex;
        state.FindExponentiation=false;
        state.singDivision.ifSingDivision=AuxExponentiation.whateverBoolTest;
        state.FirstNumber=Number;
        state.SecondNumber="";
        
    }

    return state;
}

FindNumberStateFunc FindNumber::FindDivisionFunc(bool FindDivision , bool FindDivisionFromExponetiation , int AmountOfMultiplications , sstringByUser stringByUser, int currentIndex,int LeftOrRight, string divisor, string Number, string NumberForMult, float numberNumber){

    StringResultAndUpdateIndex AuxExponentiation , NumberForDivision;
    FindNumberStateFunc FindExponentiationResult;
    bool FindExponentiation=false, Left=false , Right=false ;
    FindNumberStateFunc state;

    if(LeftOrRight==0){Left=true;}
    if(LeftOrRight==1){Right=true;}

    if(AmountOfMultiplications%2==0){
            NumberForDivision=FindDividend(currentIndex , stringByUser, LeftOrRight);
            currentIndex=NumberForDivision.UpdateIndex;

            if(NumberForDivision.whateverBoolTest){
                FindExponentiationResult=FuncFindExponentiation( AmountOfMultiplications , currentIndex ,LeftOrRight, stringByUser, NumberForDivision.StringResult , NumberForDivision.StringResult );
                NumberForDivision.StringResult=to_string(FindExponentiationResult.result);
                FindExponentiation=FindExponentiationResult.FindExponentiation;
                currentIndex=FindExponentiationResult.newIndex;
            }   

            if(FindDivisionFromExponetiation){
                if(Left){numberNumber= DivisionOfNumbersInStringType(NumberForDivision.StringResult , divisor) * numberNumber;}
                if(Right){numberNumber= DivisionOfNumbersInStringType( divisor, NumberForDivision.StringResult ) * numberNumber;}
                FindDivisionFromExponetiation=false;
                string AuxMult=to_string(numberNumber);
                numberNumber=MultiplicationOfNumbersInStringType(AuxMult, Number);
                
            }else{
                cout<<"Realize the division between  NumberForDivision.StringResult: "<<NumberForDivision.StringResult<<" Number: "<<Number;
                cout<<endl<<"And Mutiplies with numbernumber:"<<numberNumber<<endl;
                numberNumber= DivisionOfNumbersInStringType(Number, NumberForDivision.StringResult) * numberNumber;
                cout<<"numberNumber in findDivisionFunc: "<<numberNumber;
            }
            
            Number="";
            
            state.result=numberNumber;
            state.FirstNumber="";
            state.SecondNumber=NumberForMult;
            state.FindDivision=false;
            state.newIndex=currentIndex;

            return state;

            
    }else{
            
            NumberForDivision=FindDividend( currentIndex , stringByUser, LeftOrRight);
            if(NumberForDivision.whateverBoolTest){
                FindExponentiationResult=FuncFindExponentiation( AmountOfMultiplications , currentIndex ,LeftOrRight, stringByUser, NumberForDivision.StringResult , NumberForDivision.StringResult );
                NumberForDivision.StringResult=to_string(FindExponentiationResult.result);
               
                FindExponentiation=FindExponentiationResult.FindExponentiation;
                currentIndex=FindExponentiationResult.newIndex;
            }   

            if(FindDivisionFromExponetiation){
                
                if(Left){numberNumber= DivisionOfNumbersInStringType(NumberForDivision.StringResult , divisor) * numberNumber;}
                if(Right){numberNumber= DivisionOfNumbersInStringType( divisor, NumberForDivision.StringResult ) * numberNumber;}                FindDivisionFromExponetiation=false;
                string AuxMult=to_string(numberNumber);
                numberNumber=MultiplicationOfNumbersInStringType(AuxMult, NumberForMult);

            }else{
                if(Left){numberNumber= DivisionOfNumbersInStringType(NumberForDivision.StringResult , NumberForMult) * numberNumber;}
                if(Right){numberNumber= DivisionOfNumbersInStringType(NumberForDivision.StringResult , NumberForMult) * numberNumber;}

            }

            NumberForMult="";
            currentIndex =+ NumberForDivision.UpdateIndex;

            state.result=numberNumber;
            state.FirstNumber=Number;
            state.SecondNumber=NumberForMult;
            state.FindDivision=false;
            state.newIndex=currentIndex;



            return state;
    }

}


FindNumberFinalResult FindNumber::FuncFindNumber(sstringByUser stringByUser , int CurrentIndex , int LeftOrRight){

    // cout<<endl<<"string by user: "<<stringByUser.sstringg<<endl;
    // cout<<endl<<"current index: "<<CurrentIndex<<endl;
    // cout<<endl<<"left or right: "<< LeftOrRight<<endl;
    // cout<<endl<<"First Caracter: "<<stringByUser.sstringg[CurrentIndex]<<endl;

    int  I=0 , checkIfDubleDot=0 , checkIfDubleDotForMultNumber=0 , AmountOfMultiplications=0;

    string Number="" , Expoent="" , NumberForMult="", divisor="" ;

    StringResultAndUpdateIndex AuxExponentiation , NumberForDivision;

    FindNumberStateFunc FindExponentiationResult , FindDivisionResult;
    bool findMultiplication=false , FindExponentiation=false , FindTheNextNumberAndStop=false , AchiveNumber=false;
    bool dubleDot=false , dubleDotForMultNumber=false , FindDivision=false , FindDivisionFromExponetiation=false;
    bool Left= false , Right=false;
    float numberNumber=1;

    FindNumberFinalResult RESULT;

    if(LeftOrRight==0){Left=true;}
    if(LeftOrRight==1){Right=true;}
    
    if(Left){
        
        I=(CurrentIndex>0)?CurrentIndex-1:CurrentIndex;
        
        for(I; I>=0; I--){
            FindNumberPrint( Right , Left , Number ,NumberForMult , divisor , Expoent , dubleDot, findMultiplication,FindExponentiation, AchiveNumber ,dubleDotForMultNumber ,FindDivision , FindDivisionFromExponetiation , numberNumber , I);

            if((I==0) && (AmountOfMultiplications==0) && stringByUser.sstringg[0]==' '){
                numberNumber=MultiplicationOfNumbersInStringType(Number,"")*numberNumber;
            }
            if ((stringByUser.sstringg[I] == '+') || (stringByUser.sstringg[I] == '-')) { 
                
                bool NumberContentDigit=false;
                for(int k=0 ; k<Number.size() ; k++){
                    if(isdigit(Number[k])){NumberContentDigit=true;}
                }
                if( (AmountOfMultiplications==0 ) && (NumberContentDigit) ){numberNumber=MultiplicationOfNumbersInStringType(Number, "");}
                break; 
            }
            
            if(stringByUser.sstringg[I]=='^'){FindExponentiation=true;}
            
            if(FindExponentiation){
                
                FindExponentiationResult=FuncFindExponentiation( AmountOfMultiplications , I ,LeftOrRight, stringByUser, Number , NumberForMult );
               
                if(FindExponentiationResult.singDivision.ifSingDivision){
                    divisor=to_string(FindExponentiationResult.result);
                    FindDivisionFromExponetiation=true;

                }else{

                    numberNumber=FindExponentiationResult.result*numberNumber;
                }

                Number=FindExponentiationResult.FirstNumber;
                NumberForMult=FindExponentiationResult.SecondNumber;
                FindExponentiation=FindExponentiationResult.FindExponentiation;
                I=FindExponentiationResult.newIndex;
                
                
            }

            if(stringByUser.sstringg[I]=='/'){FindDivision=true;}
            if(FindDivision || FindDivisionFromExponetiation){
                FindDivisionResult= FindDivisionFunc( FindDivision ,  FindDivisionFromExponetiation , AmountOfMultiplications , stringByUser, I,LeftOrRight, divisor, Number, NumberForMult, numberNumber);
                
                numberNumber=FindDivisionResult.result;
                Number=FindDivisionResult.FirstNumber;
                NumberForMult=FindDivisionResult.SecondNumber;
                I=FindDivisionResult.newIndex;
                FindDivision=FindDivisionResult.FindDivision;
                FindDivisionFromExponetiation=FindDivisionResult.FindDivision;

            }

            
            if(stringByUser.sstringg[I]=='.'){checkIfDubleDot++;}
            if(checkIfDubleDot>1){dubleDot=true;}
            
            if((stringByUser.sstringg[I]=='*')){
                
                (findMultiplication==true)?I:I--;
                if(AmountOfMultiplications%2==0){findMultiplication=true;}
                AmountOfMultiplications++;
                
            }

            
            if( (isdigit(stringByUser.sstringg[I]) || !(dubleDot) ) && !(findMultiplication) && !(FindExponentiation) && (stringByUser.sstringg[I]!='*')){

                Number=stringByUser.sstringg[I]+Number;

            }

            if(findMultiplication && !FindTheNextNumberAndStop && !FindExponentiation){
                
                if ((stringByUser.sstringg[I]!='*') && !(dubleDotForMultNumber)){NumberForMult=stringByUser.sstringg[I]+NumberForMult;}

                if((stringByUser.sstringg[I]=='.')){checkIfDubleDotForMultNumber++;}
                if(checkIfDubleDotForMultNumber>1){dubleDotForMultNumber=true;}

                if(isdigit(stringByUser.sstringg[I])){AchiveNumber=true;}
    
                if(AchiveNumber){
                    
                    if(stringByUser.sstringg[I] == ' ' || stringByUser.sstringg[I] == '*' || (I==0)){

                        findMultiplication=false;
                        FindTheNextNumberAndStop= true;
                        AchiveNumber=false;
                    }
                }

                if(FindTheNextNumberAndStop){
                   numberNumber= MultiplicationOfNumbersInStringType(Number , NumberForMult)* numberNumber;
                   findMultiplication=false;
                   FindTheNextNumberAndStop=false;
                   dubleDotForMultNumber=false;
                   dubleDot=false;

                   Number="";
                   NumberForMult="";

                   checkIfDubleDotForMultNumber=0;
                   checkIfDubleDot=0;
                   I++;
                }
            }

            
        
            
           
        }
        
        
    }

    if(Right){

        
        I=CurrentIndex<stringByUser.length?CurrentIndex+1:CurrentIndex;
        
        for (I; I < stringByUser.length; I++) {
            FindNumberPrint( Right , Left , Number ,NumberForMult , divisor , Expoent , dubleDot, findMultiplication,FindExponentiation, AchiveNumber ,dubleDotForMultNumber ,FindDivision , FindDivisionFromExponetiation , numberNumber , I);
            
            if((I==(stringByUser.length-1)) && (AmountOfMultiplications==0) && stringByUser.sstringg[(stringByUser.length-1)]==' '){
                numberNumber=MultiplicationOfNumbersInStringType(Number,"")*numberNumber;
            }
            
            if (stringByUser.sstringg[I] == '^') { FindExponentiation = true; }
            if (FindExponentiation) {
                FindExponentiationResult = FuncFindExponentiation(AmountOfMultiplications, I,LeftOrRight, stringByUser, Number, NumberForMult);
                
                if (FindExponentiationResult.singDivision.ifSingDivision) {
                    divisor = to_string(FindExponentiationResult.result);
                    FindDivisionFromExponetiation = true;
                } else {
                    numberNumber = FindExponentiationResult.result * numberNumber;
                }
                
                Number = FindExponentiationResult.FirstNumber;
                NumberForMult = FindExponentiationResult.SecondNumber;
                FindExponentiation = FindExponentiationResult.FindExponentiation;
                I = FindExponentiationResult.newIndex;
                
            }
            
            if (stringByUser.sstringg[I] == '/') { FindDivision = true; }
            
            if (FindDivision || FindDivisionFromExponetiation) {
                
                FindDivisionResult = FindDivisionFunc(FindDivision, FindDivisionFromExponetiation, AmountOfMultiplications, stringByUser, I,LeftOrRight, divisor, Number, NumberForMult, numberNumber);
                numberNumber = FindDivisionResult.result;
                Number = FindDivisionResult.FirstNumber;
                NumberForMult = FindDivisionResult.SecondNumber;
                I = FindDivisionResult.newIndex;
                FindDivision = FindDivisionResult.FindDivision;
                FindDivisionFromExponetiation = FindDivisionResult.FindDivision;

            }
    
            if (stringByUser.sstringg[I] == '.') { checkIfDubleDot++; }
            if (checkIfDubleDot > 1) { dubleDot = true; }
    
            if ((stringByUser.sstringg[I] == '*')) {
                (findMultiplication == true) ? I : I++;
                if (AmountOfMultiplications % 2 == 0) { findMultiplication = true; }
                AmountOfMultiplications++;
            }
    
            if ((isdigit(stringByUser.sstringg[I]) || !dubleDot) && !findMultiplication && !FindExponentiation && (stringByUser.sstringg[I] != '*')) {
                Number += stringByUser.sstringg[I];
            }
    
            if (findMultiplication && !FindTheNextNumberAndStop && !FindExponentiation) {
                if ((stringByUser.sstringg[I] != '*') && !dubleDotForMultNumber) { NumberForMult += stringByUser.sstringg[I]; }
    
                if (stringByUser.sstringg[I] == '.') { checkIfDubleDotForMultNumber++; }
                if (checkIfDubleDotForMultNumber > 1) { dubleDotForMultNumber = true; }
    
                if (isdigit(stringByUser.sstringg[I])) { AchiveNumber = true; }
    
                if (AchiveNumber) {
                    if (stringByUser.sstringg[I] == ' ' || stringByUser.sstringg[I] == '*' || (I == stringByUser.length - 1)) {
                        findMultiplication = false;
                        FindTheNextNumberAndStop = true;
                        AchiveNumber = false;
                    }
                }
    
                if (FindTheNextNumberAndStop) {
                    numberNumber = MultiplicationOfNumbersInStringType(Number, NumberForMult) * numberNumber;
                    findMultiplication = false;
                    FindTheNextNumberAndStop = false;
                    dubleDotForMultNumber = false;
                    dubleDot = false;
    
                    Number = "";
                    NumberForMult = "";
    
                    checkIfDubleDotForMultNumber = 0;
                    checkIfDubleDot = 0;
                    I--;
                }
            }

            if ((stringByUser.sstringg[I] == '+') || (stringByUser.sstringg[I] == '-')) { 
                
                bool NumberContentDigit=false;
                for(int k=0 ; k<Number.size() ; k++){
                    if(isdigit(Number[k])){NumberContentDigit=true;}
                }
                if( (AmountOfMultiplications==0 ) && (NumberContentDigit) ){numberNumber=MultiplicationOfNumbersInStringType(Number, "");}
                break; 
            }
            
            
        }
    }

    RESULT.NewIndex=I==-1?0:I;
    RESULT.result=numberNumber;
    cout<<"result: "<<RESULT.result;
    return RESULT;
   
}

void FindNumber::FindNumberPrint(bool Rigth , bool Left , string Number , string NumberForMult ,string Divisor , string Expoent , bool dubleDot, bool findMultiplication, bool FindExponentiation, bool AchiveNumber , bool dubleDotForMultNumber , bool FindDivision , bool FindDivisionFromExponetiation , float numberNumber, int I ){

    cout<<endl<<endl<<"FindNumberPrint("<<I<<")_______________________________________________________________________: "<<endl;
    cout<<"Rigth: "<<Rigth<<endl;
    cout<<"Left: "<<Left<<endl;
    cout<<"Number: "<<Number<<endl;
    cout<<"NumberForMult: "<<NumberForMult<<endl;
    cout<<"Divisor: "<<Divisor<<endl;
    cout<<"Expoent: "<<Expoent<<endl;
    cout<<"doble dot: "<<dubleDot<<endl;
    cout<<"findMultiplication: "<<findMultiplication<<endl;
    cout<<"FindExponentiation: "<<FindExponentiation<<endl;
    cout<<"AchiveNumber: "<<AchiveNumber<<endl;
    cout<<"dubleDotForMultNumber: "<<dubleDotForMultNumber<<endl;
    cout<<"FindDivision: "<<FindDivision<<endl;
    cout<<"FindDivisionFromExponetiation: "<<FindDivisionFromExponetiation<<endl;
    cout<<"numberNumber: "<<numberNumber<<endl;
    cout<<endl<<"___________________________________________________________________________________|"<<endl;

}

FindNumberFinalResult FindNumber::Get(sstringByUser stringByUser , int CurrentIndex , int LeftOrRight){

    return FuncFindNumber( stringByUser , CurrentIndex , LeftOrRight);   
}

 