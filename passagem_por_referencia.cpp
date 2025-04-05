#include <iostream>
#include <cstdlib>
#include <cstdbool>

using namespace std;

void limpar_tela(){
    system("cls");
};



/* exercicio 1************************************************************************************************/

void exercicio_1(){


    int *pt=NULL, x=0 , i=1;

    while (i==1)
    {
        limpar_tela();
        cout<<"exercicio 1........................................................................................:"<<endl;


        cout<<"O endereco para o qual ponteiro pt aponta e: "<<&pt<<endl;
        cout<<endl;

        cout<<"Digite um valor para a variavel X do programa: ";
        cin>>x;
        cout<<endl;

        pt=&x;
        
        cout<<"Apos o seu ponteiro pt apontar para a variavel x esse e o atual valor atribuido ao ponteiro: "<<*pt<<endl;
        cout<<endl;

        cout<<"O endereço da variavel X e: "<<&x<<endl;
        cout<<endl;

        *pt=(*pt )* 10;

        cout<<"O valor atribuido pelo poteiro pt no estado atual do programa e: "<<*pt<<endl;
        cout<<endl;

        *pt += 10;

        cout<<"O valor atribuido pelo poteiro pt no estado atual do programa e: "<<*pt<<endl;
        cout<<endl;

        cout<<"............................................................................................|"<<endl;
        cout<<endl;


         cout<<"Se deseja sair digite 0 para continuar digite 1"<<endl;
        cin>>i;

    }


}

void exercicio_2(){

    limpar_tela();
    cout<<"exercicio 2........................................................................................:"<<endl;

    int enter;

    int a=10, b=20, c=30, v[3], *pti, *pti1, *pti2;
    pti1 = &a;
    pti2 = &b;

    *pti1=c;
    *pti2=c;

    pti=v;

    for(int i=0 ; i<3 ; i++){

        *(pti+i)=i+1;

    };

    for (int i = 0; i < 3; i++)
    {
        cout<<"O valor contido na posicao "<<i<<" do vetor v[] e "<<v[i]<<endl;
    }
    cout<<endl;

    cout<<"o valor contido na variavel (a) e: "<<a<<endl;
    cout<<"o valor contido na variavel (b) e: "<<b<<endl;
    cout<<"o valor contido na variavel (c) e: "<<c<<endl;
    cout<<endl;

    *(pti+0)=a+99;

    cout<<"o valor da primeira posicao do vetor v apos a operacao { *(pti+0)=a+99 } e: "<<*(pti+0)<<endl;


    *pti1=a;
    *pti2=b;

    v[0]=(*pti1)+(*pti2);

    v[1]=(*pti2);

    v[2]=(*pti);

    ++(*pti2);

    *(pti+1)-=1;

    cout<<"o valor contido na variavel (a) na segunda chamada e: "<<a<<endl;
    cout<<"o valor contido na variavel (b) na segunda chamada e: "<<b<<endl;
    cout<<"o valor contido na variavel (c) na segunda chamada e: "<<c<<endl;
    cout<<endl;

    cout<<"........................................................................................................|"<<endl;
    cout<<"para sair digite 1 e aperte enter: ";
    cin>>enter;
}

void exercicio_3(){

    limpar_tela();

    int x = 23, enter=0; 
    float y = 9.7;

    int *pti1=&x ;
    float *pti2=&y ;

    cout<<"exercicio 3........................................................................................:"<<endl;
    cout<<endl;

    ++(*pti1);

    cout<<"O valor atribuido aos ponteiros pti1 que aponta para a variavel (x) e: "<<*pti1<<endl;
    cout<<endl;
    cout<<"O valor atribuido aos ponteiros pti2 que aponta para a variavel (y) e: "<<*pti2<<endl;
    cout<<endl;
    cout<<"A soma das variaveis (x) e (y) apatir dos ponteiros pti1 e pti2 e: "<< (*pti1)+(*pti2)<<endl;
    cout<<endl;

    cout<<"o endereco de memoria localizado a 16 bytes da variavel (x) e: "<<&pti1+4<<endl;
    cout<<endl;

    float **pti3 = &pti2;

    ++(*pti3);

    cout<<"O endereco de pti3 e: "<<*pti3<<endl;
    cout<<"O endereco de pti2 e: "<<pti2<<endl;


    
    cout<<"........................................................................................................|"<<endl;
    cout<<"para sair digite 1 e aperte enter: ";
    cin>>enter;

}

void exercicio_4(float &a , float &b){

    limpar_tela();
    int i=1;
    
    cout<<"exercicio 4........................................................................................:"<<endl;
    cout<<endl;

        float variavel_temporaria=0;

        variavel_temporaria = a;
        a = b;
        b = variavel_temporaria;

        cout<<"se deseja sair digite 0 para continuar digite 1"<<endl;
        cin>>i;

};

void exercicio_5(int num, int div, int *q, int *r){

    *q=num/div;
    *r=num%div;
};

void interface_para_exercicio_5(){
    limpar_tela();

    cout<<"exercicio 5........................................................................................:"<<endl;
    cout<<endl;

    int num=0 , div=0 , q=0 ,r=0, enter=0;
    cout<<"realize uma divisao. Primeiramente digite o dividendo e posteriormente o divisor"<<endl;
    cout<<"dividendo: "<<endl;
    cin>>num;
    cout<<"divisor: "<<endl;
    cin>>div;

    exercicio_5( num, div , &q , &r);
        cout << "Quociente: " << q << endl;
        cout << "Resto: " << r << endl;

    cout<<"........................................................................................................|"<<endl;
    cout<<"para sair digite 1 e aperte enter: ";
    cin>>enter;
}



bool exercicio_6(int tam, int vet[], int *par, int *impar, int *negativos){

    int qtn_num_pares=0, qtn_num_impares=0 , qtn_num_negativos=0;

    for(int i= 0 ; i<tam ; i++){
        
        if(vet[i]%2==0){
            qtn_num_pares++;
        }else{
            qtn_num_impares++;
        }
        if(vet[i]<0){
            qtn_num_negativos++;
        }

        
    }
    if(qtn_num_negativos!=0){
           return true;
    }

    return false;
    
};

void exercicio_7(int vet[] , int n){
    
    int h=1;

    while(h==1){

        for (int i =0; i<n ; i++){
            vet[i]=exercicio_4(vet[i], vet[n-1-i]); 
        }

        for(int k = 0; k < n ; i++){

            cout<<"O valor do seu vetor vet["<<i<<"] apos a inversao e : "<<*vet[i]<<endl;

        }
    }
}

void interface_para_exercicio_7(){

    limpar_tela();

    cout<<"exercicio 7........................................................................................:"<<endl;
    cout<<endl;

    cout<<"prencha o vetor dado , primeiramente diga quantos dados voce ira guardar e posteriormente o preencha."<<endl;

    int tamanho=0, enter=0;
    cout<<"tamanho: ";
    cin>>tamanho;

    float *vetor_passado_pelo_usuario= new float[tamanho];

    for(int i=0; i<tamanho ; i++){
        cout<<"digite o valor do seu vetor para a posição "<<i<<": ";
        cin>>*vetor_passado_pelo_usuario[i];
        cout<<endl;

        cout<<"faltam "<<tamanho-i<<" elementos."<<endl;

    }

    exercicio_7(vetor_passado_pelo_usuario , tamanho);

    cout<<"........................................................................................................|"<<endl;
    cout<<"para sair digite 1 e aperte enter: ";
    cin>>enter;

}

int main(){

    int i=1 , escolha=0;

    while (i==1)
    {
        limpar_tela();

        cout<<"menu..............................:"<<endl;
        cout<<endl;
        cout<<"1.exercicio 1............|"<<endl;
        cout<<"2.exercicio 2............|"<<endl;
        cout<<"3.exercicio 3............|"<<endl;
        cout<<"5.exercicio 5............|"<<endl;
        cout<<"7.exercicio 7............|"<<endl;
        cout<<"0.sair...................|"<<endl;
        cout<<endl;

        cout<<"..................................|"<<endl;
        cout<<endl;

        cout<<"digite sua escolha: ";
        cin>>escolha;
        cout<<endl;

        if(escolha>=0 && escolha<9){

            switch (escolha)
            {
            case 1:
                exercicio_1();
                break;
            case 2:
                exercicio_2();    
                break;
            case 3:
                exercicio_3();
                break;    
            case 5:{ 

               interface_para_exercicio_5();
                break;        
            }
            case 7:{

                interface_para_exercicio_7();
                break;
            }
            case 0:
                limpar_tela();
                return 0;
                break;
            default:
                cout << "Escolha inválida!" << endl;
                break;
            }

        }else{
            cout<<"escolha um numero valido!!"<<endl;
        };

    }
    

    return 0;
}