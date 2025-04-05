#include <iostream>
#include <cmath>
#include "../headers/poligono.h"

using namespace std;

// Implementação do construtor
Poligono::Poligono(int lados, float tamanho) {
    numLados = lados; 
    tamLado = tamanho;
}

// Implementação das funções
float Poligono::area() {
    return numLados * pow(tamLado, 2) / (4 * tan(3.1416 / numLados));
}

float Poligono::perimetro() {
    return numLados * tamLado;
}

float Poligono::angInterno() {
    return 180.0 * (numLados - 2) / numLados;
}

// Testando no main
int main() {
    Poligono poligono(5, 10.0); // Criando um polígono com 5 lados de tamanho 10

    cout << "Área: " << poligono.area() << endl;
    cout << "Perímetro: " << poligono.perimetro() << endl;
    cout << "Ângulo Interno: " << poligono.angInterno() << endl;

    return 0;
}
