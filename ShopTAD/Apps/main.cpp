#include <iostream>
#include "Shop.h"

using namespace std;

int main(){
    

    int AmountOfItens ; 
    string ProductName ;
    float AmountOfProductsSales;
    bool CONTINUE=true;


    Shop shop;

    shop.ClearTerminal();

    cout<<"Wirite the amount of product sales: ";
    cin>>AmountOfItens;
    cout<<endl;
    shop.SetItens(AmountOfItens);
    shop.AmountSalesItens();

    
    shop.GetVectorAmountSalesMade();



    shop.TotalSalesValue();
    shop.GetTheLargePriceValue();

    shop.~Shop();

}

