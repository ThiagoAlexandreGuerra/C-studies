#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Shop{

    private:

        int AmountOfProducts=0;

        int* NumberOfSaleMade = nullptr;
        float* CumulativeSalesPrices = nullptr;
        float* productValues = nullptr;
        string* productsNames = nullptr;


        float* creatingAnDynamicFloatVector(int Length);
        string* creatingAnDynamicStringVector(int Length);
        int* creatingAnDynamicIntVector(int Length);


    public:

        void GetVectorAmountSalesMade();
        void ClearTerminal();
        void SetItens(int NumberOfItens);
        void AmountSalesItens();
        void TotalSalesValue();
        void GetTheLargePriceValue();
            ~Shop();

};
#endif