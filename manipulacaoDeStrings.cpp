#include <iostream>
using namespace std;

void InverteVetor(char vetor[] , int TamanhoVetor){

    char* RecebeVetor= new char [TamanhoVetor];

    cout << "O vetor que voce passou foi: " <<endl;
    cout<<endl;

    for(int i = 0 ; i<TamanhoVetor ; i++){
        
        cout<<"vetor na posicao "<<i<<" e igual a : "<<vetor[i]<<endl;
    }
    cout<<endl;

    for(int k=0 ; k<TamanhoVetor; k++){

        RecebeVetor[k]=vetor[TamanhoVetor-1-k];
        
    }

    cout<< "O vetor copia invertida e: "<<endl;
    cout<<endl;

    for(int l=0 ; l<TamanhoVetor ; l++){
        
        cout<<"vetor na posicao "<<l<<" e igual a : "<<RecebeVetor[l]<<endl;
        
    }
    cout<<endl;

    delete[] RecebeVetor;
    
}

int main(){

    char* vetor= nullptr;
    char inputStringValue; 
    int capacidade=1;
    int contador=0;

    vetor= new char[capacidade];
    
    cout<<"Preencha o seu vetor com quantos valores desejados, um por um, e quando acabar digite 0 ";

    while (true)
    {

        cin>>inputStringValue;

        if(inputStringValue=='0'){
              break;
        }   

        vetor[contador]=inputStringValue;

        char *NovoVetor= new char[capacidade];

        for(int i= 0; i<capacidade ; i++){
            NovoVetor[i]=vetor[i];
        }


        delete[] vetor;

        vetor=NovoVetor;
        capacidade++;
        contador++;
    }

   InverteVetor(vetor,contador);

    delete[] vetor;
    
}