#include <iostream>
#include <cstdbool>
#include <cmath>

using namespace std;
#define tamnhoVetor 6 

int FuncaoRecursivaDeSoma(int vetor[], int TamanhoDoVetor){

    if(TamanhoDoVetor<=0){

        return 0;
    }
    
    return vetor[TamanhoDoVetor-1]+ FuncaoRecursivaDeSoma(vetor , TamanhoDoVetor-1);
}

int main(){

    int vetorTest[tamnhoVetor]={10, 2, 30 ,  40 , 50 , 60};

    int RetornoSoma=FuncaoRecursivaDeSoma(vetorTest , tamnhoVetor);

    cout<<"A soma dos termos do seu vetor é :" << RetornoSoma<<endl;

    return 0;
} 