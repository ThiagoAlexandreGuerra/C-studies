#include "Shop.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

void Shop::GetVectorAmountSalesMade(){

    cout<<"Product amount sales records________________________:"<<endl;
    for(int i=0; i<AmountOfProducts ; i++){
        cout<<"Product "<<"["<<i<<"]"<<" : "<<NumberOfSaleMade[i]<<endl;
    }
}

void Shop::ClearTerminal(){

    system("CLS");
    
}

float* Shop::creatingAnDynamicFloatVector(int Length){

   return new float[Length]();

}

int* Shop::creatingAnDynamicIntVector(int Length){

    return new int[Length]();
    
}

string* Shop::creatingAnDynamicStringVector(int Length){

    string* vector= new string[Length];
    return vector;
}



void Shop::SetItens(int NumberOfItens){

    AmountOfProducts=NumberOfItens;

    productValues=creatingAnDynamicFloatVector(NumberOfItens);
    productsNames=creatingAnDynamicStringVector(NumberOfItens);

    string name="";
    float price=0;

    cout<<endl;

    
    for(int i=0 ; i<NumberOfItens ; i++){
        
        ClearTerminal();
        cout<<"Wirite the Iten names and respect price, press 0 anytime for exist:"<<endl;
        cout<<"Iten Name: ";
        cin>>name;
        for(char& c : name){
            c = tolower(c);
        }
        cout<<endl;
        cout<<"Iten Price: ";
        cin>>price;
        productValues[i]=price;
        productsNames[i]=name;


    }

    ClearTerminal();

};

void Shop::AmountSalesItens(){

    

    string ProductName ;
    float AmountOfProductsSales;
    bool CONTINUE=true;

    NumberOfSaleMade=creatingAnDynamicIntVector(AmountOfProducts);
    CumulativeSalesPrices=creatingAnDynamicFloatVector(AmountOfProducts);

    while (CONTINUE)
    {
        
        cout<<"Wirite the product name and amount sales____________________________________________________: ";
        cout<<endl<<endl;
        cout<<"product name: ";
        cin>>ProductName;
        cout<<"amount of product sales: ";
        cin>>AmountOfProductsSales;
        cout<<endl;
        
        for(char& c : ProductName){
        c = tolower(c);
    }

        for(int i=0 ; i<AmountOfProducts ; i++){

            if(productsNames[i]==ProductName){
                NumberOfSaleMade[i]=AmountOfProductsSales;
                CumulativeSalesPrices[i]+=(productValues[i])*AmountOfProductsSales;
            }

        }

        cout<<"you have another product want set the amount sales,press 1 for continue end 0 for exist: "<<endl;
        cin>>CONTINUE;
        cout<<"_____________________________________________________________________________|"<<endl;
        ClearTerminal();
    }



};

void Shop::TotalSalesValue(){

    
    if (!CumulativeSalesPrices) {
        cout << "No sales recorded yet." << endl;
        return;
    }

    float total=0;
    for(int i=0; i<AmountOfProducts ; i++){
        total+=CumulativeSalesPrices[i];
    }

    cout<<endl;
    cout<<"__________________________________________________________________:"<<endl;
    cout<<endl;
    cout<<"Cumulative Sales prices: "<<total<<endl;
    cout<<endl;
    cout<<"__________________________________________________________________|"<<endl;

}

void Shop::GetTheLargePriceValue(){

    
    GetVectorAmountSalesMade();
    
    
    float first=0, second=0 , third=0;
    int indiceFirst=0 , indiceSecond=0 , indiceThird=0;  

    for(int i=0 ; i<AmountOfProducts ; i++){

        if(productValues[i]>first){
            indiceThird=indiceSecond;
            third=second;

            indiceSecond=indiceFirst;
            second=first;

            first=productValues[i];
            indiceFirst=i;


        }else if(productValues[i]>second){

            indiceThird=indiceSecond;
            third=second;

            second=productValues[i];
            indiceSecond=i;
        }else if(productValues[i]>third){
            third=productValues[i];
            indiceThird=i;
        }
    }

    cout<<endl;

    cout<<"__________________________________________________________________:"<<endl;
    cout<<"The products with the large prices is: "<<endl;
    cout<<"First place: "<<productsNames[indiceFirst]<< "     | Amount sales: "<<NumberOfSaleMade[indiceFirst]<<"      | Price: "<<first<<endl;
    cout<<"second place: "<<productsNames[indiceSecond]<< "    | Amount sales: "<<NumberOfSaleMade[indiceSecond]<<"      | Price: "<<second<<endl;
    cout<<"Third place: "<<productsNames[indiceThird]<< "     | Amount sales: "<<NumberOfSaleMade[indiceThird]<<"      | Price: "<<third<<endl;
    cout<<"_______________________________________________________________________|";



}

Shop::~Shop(){

    delete []NumberOfSaleMade;
    delete []CumulativeSalesPrices;
    delete []productValues;
    delete []productsNames;
}