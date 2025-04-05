#ifndef READINGCIPHER_H
#define READINGCIPHER_H

#include <iostream>
#include <map>  // Para armazenar as letras de forma mais eficiente

using namespace std;

struct Letter {
    int Frequency;
    float Percent;
    int length;
    int* Positions;  

    // Construtor
    Letter(int len = 0) : Frequency(0), Percent(0), length(len), Positions(nullptr) {
        if (length > 0) {
            Positions = new int[length];  // Aloca o vetor apenas se o tamanho for maior que zero
        }
    }

    // Método para preencher os valores do vetor
    void preencher(int position, int index) {
        if (Positions != nullptr && index >= 0 && index < length) { 
            Positions[index] = position;
        }
    }

    // Destrutor para liberar a memória
    ~Letter() {
        delete[] Positions;  // Libera a memória do vetor
    }
};

class ReadingCipher {
    private:
        char cipher;
        map<char, Letter> letters;  // Mapeia letras para suas estruturas

    public:
        // Construtor da classe
        ReadingCipher(char UserCipher);

        // Método para configurar a frequência de uma letra
        void setFrequency(char letter, int freq);

        // Método para exibir as frequências armazenadas
        void printFrequencies();
};

#endif  // READINGCIPHER_H
