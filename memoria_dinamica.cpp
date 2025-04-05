#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdbool>

using namespace std;

void exercicio_1(){

    

}


int main(){

    int escolha=0;
    bool continuar=true;

    while (continuar)
    {
    
            cout<<"menu..............................:"<<endl;
            cout<<endl;

            cout<<"1.exercicio_1...................:"<<endl;
            cout<<"0.sair..........................:"<<endl;

            cin>>escolha;

            switch (escolha)
            {
            case 1:
                exercicio_1();
                break;
            
            default:
                break;
            }
    }
    



    return 0;
}