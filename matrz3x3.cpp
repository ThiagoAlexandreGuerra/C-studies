#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define LIN 8
#define CLM 2
#define CAM 2

void le_matriz(int matriz[LIN][CLM][CAM]) {
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < CLM; j++) {
            for (int k = 0; k < CAM; k++) {
                cout << setw(4) << matriz[i][j][k];
                
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main(){

    int matriz[LIN][CLM][CAM];

    int elementos[8][2]={
                         {2,3},
                         {5,6},
                         {7,8},
                         {6,4},
                         {2,3},
                         {5,6},
                         {7,8},
                         {6,4}

                        };
    

    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < CLM; j++) {
            for (int k = 0; k < CAM; k++) {
                matriz[i][j][k] = elementos[i][j];
            }
        }
    }


    le_matriz(matriz);

  return 0;                
}