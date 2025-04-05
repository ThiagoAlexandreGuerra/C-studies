#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>

using namespace std;

int randomNumber() {
    return rand() % 10000000; 
}

int* creatingArrayRandom(int len) {
    int* vet = new int[len];

    for (int i = 0; i < len; i++) {
        vet[i] = randomNumber();
    }

    return vet; 
}


void bubbleSort(int vet[], int len) {
    for (int i = len - 1; i > 0; i--) {  // Laço externo
        for (int j = 0; j < i; j++) {   // Laço interno
            if (vet[j] > vet[j + 1]) {  // Condição de troca
                cout << "Troca: " << vet[j] << " com " << vet[j + 1] << endl;
                swap(vet[j], vet[j + 1]); // Troca correta
            }
        }
    }

    // Exibir o vetor ordenado
    for (int i = 0; i < len; i++) {
        cout << "Posição: " << i << " Valor: " << vet[i] << endl;
    }
}

void selectionSort(int vet[], int len) {

    for(int i=0 ; i<len-1; i++){

        int min=i;

        for(int j=i+1; j<len ; j++){
            if(vet[min]>vet[j]){
                min=j;
            }
        }

        int temp=0;
        if(vet[i]<vet[min]){
            temp=vet[i];
            vet[i]=vet[min];
            vet[min]=temp;
        }
    }
}

void reading(int vet[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "Position: " << i << " | Value: " << vet[i] << endl;
    }
    cout << "-----------------------------------------------------------------|" << endl;
}

int main() {
   
   int vet[10]={2,5,6,4,3,6,7,0,8,9};

   selectionSort(vet,10);

    return 0;
}
