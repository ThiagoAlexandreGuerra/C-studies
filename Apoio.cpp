#include <iostream>
using namespace std;

void imprimeIntervalo(int a, int b, int inc) {
    if (a > b) {  // Caso de intervalo inválido
        cout << "Digite um intervalo válido" << endl;
        return;  // Termina a execução da função
    }

    cout << a << endl;  // Imprime o valor atual de a

    if (a + inc <= b) {  // Caso recursivo
        imprimeIntervalo(a + inc, b, inc);
    }
}

int main() {
    imprimeIntervalo(1, 20, 2);  // Exemplo de chamada
    return 0;
}
