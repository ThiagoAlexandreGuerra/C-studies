#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std; 

#define LIN 6
#define CLM 6
#define PRF 6

void le_matriz(int matriz[LIN][CLM][PRF]) {
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < CLM; j++) {
            for (int k = 0; k <PRF ; k++){

                cout << setw(4) << matriz[i][j][k]; 
            }
            cout<< endl;


        }
        cout << endl;
    }
}

int main() {
    int matriz[LIN][CLM][PRF];

    
    
    for(int k = 0; k < PRF ; k++){
        for (int i = 0; i < LIN; i++) {
            for (int j = 0; j < CLM; j++) {

                matriz[i][j][k] = i * LIN + j * CLM + k;  

                if(j==0 && i==0){
                    matriz[k][0][0]= 22;
                }
            }
        }

    }

    
   // le_matriz(matriz);
    for(int i=0 , j=0 ; j<10 && i<10 ; i++, j++){
        cout<<k<<"e"<<i<<endl;
   }
    

    return 0;
}

int funtfdu(){

int i=0;
   for(int i=0 , k=0 ; k<10 && i<10 ; i++, k++){
        cout<<k<<"e"<<i<<endl;
   }
    
}