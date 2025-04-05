#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void reading(int vet[], int len) {
    for (int i = 0; i < len; i++) {
        cout << "Position: " << i << " | Value: " << vet[i] << endl;
    }
    cout << "-----------------------------------------------------------------|" << endl;
}

void exercice3(int *var){

    cout<<"The address of variable (var) is: "<<&var<<endl;
    
}

void exercise1(){

    int var=0;
    int *ptr=NULL;
    var=10;
    ptr=&var;
    exercice3(&var);
}

void exercise2(){

    /*
        Poniter is a variable that storage a address of another variable. 
        the assingments is make by using of sing & that means address of.
    */
}

void exercise4(){

    /*
        a) in this case the sing of (*) , means that the pointer was initialized.
        b) the sing (*) is used here for the access of value of pointer.
        c) this time the sing is used for the assingmentes of the variable.
        d) in this case the sing of (*) is used in arithmetic of pontiers.  
    */
}

void exercise5(){

    /*
        The alternative that response correctly the question is letter (A).
    */
}

void exercise6(){

    /*
       (D) alternative. 
    */
}

void exercise7(){

    int i = 3, j = 5;
    int *p = &i, *q = &j;

    /*
        (a) p == &i , returns true.
        (b) *p - *q,  returns -2.
        (c) **&p , remember that **&p is same thing than *p , thereformore returns 3.
        (d) 3*-*p/(*q)+7 ,returns 8,8. 
    */

}

void exercise8(){
    
    cout<<"exercise 8 ----------------------------------------------------------|"<<endl;
    int i = 5, *p;
    p = &i;
    cout << p <<"\t"<< (*p+2) <<"\t"<< **&p <<"\t"<<(3**p)<<"\t"<<(**&p + 4);
    cout<<endl;
    cout<<"--------------------------------------------------------------------:"<<endl;
    

}

void exercise9(){

    /*
        letter A is only correct alternative.
    */
}

void exercise10(){
    /*
        #include <iostream>
        #define VAL 987
        int main() {
        int *p = VAL;
        cout<<*p
        return 0;
        }

        this program is incorrect, because the integer pontier p not was initialize correctly.
    */
}

void exercise11(){

    /*
        (a) Qual a diferenca entre vet[3] e *(vet+3)?
        (b) Admitindo a declaracao: int vet[8];, por que a instrucao vet++  ́e incorreta?
        (c) Admitindo a declaracao: int vet[8];, quais das seguintes express ̃oes referenciam o valor
        do terceiro elemento do vetor?

        1. *(vet+2)
        2. *(vet+3)
        3. vet+2
        4. vet+3

        a: not is nothing diference betewen the first stament e second statement.
        b: is wrong because the vector vet is only a address.
        c: the correct alternative is the first statement.

    */
}

void exercise12(){

    /*
        first program:
            4 
            5
            6
        second program:
           address of position 0.
           address of position 1.
           address of position 2.
        third program:
            4
            5
            6   
    */
}

void exercise13(){

    /*
        In the first statement the variables s is a vector that was assigment a string able for 
        access each element as a normal arrey e the second is a pointer that storage a string.
    */
}

void exercise14(){

    /*
        a: eu não vou seputar cesar.
        b: address of vector potition 0.
        c: address of vector position 11.
        d: the first letter of string.
        e: the first element address. 
    */
}

void exercise15(){

    /*
        mat[i][j] == *(*(mat+i)+j)
    */
}

void exercise16(){

    /*
        the first statment is a integer pointer and the second statment is a vector.
    */
}

void exercise17(){

    /*
        Assumindo a declaracao:
        char *itens[5] = {"Abrir", "Fechar", "Salvar", "Imprimir", "Sair"};
        Para poder escrever a instru ̧c ̃ao p = itens;, a vari ́avel p deve ser declarada como:
        (a) char p;
        (b) char *p;
        (c) char **p;
        (d) char ***p;

        The c alternative is correctly , the correct way of statement a pointer for a arrey like itens is
        char **p.
    */
}

void exercise18(){

    int n=0;
    cout<<endl;
    cout<<"exercise 18-------------------------------------------------------------:";
    cout<<endl;
    cout<<"write a value: ";
    cin>> n;

    int *vet= new int[n];

    for(int i=0; i<n ; i++){
        vet[i]=i;
    }

    reading(vet, n);

    delete []vet;
}

int main(){

    exercise8();
    exercise1();
    exercise18();
    return 0;
}