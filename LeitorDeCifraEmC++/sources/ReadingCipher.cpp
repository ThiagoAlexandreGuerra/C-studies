#include "../header/ReadingCipher.h"
#include <iomanip>

// Construtor da classe
ReadingCipher::ReadingCipher(char UserCipher) : cipher(UserCipher) {
    for (char c = 'A'; c <= 'Z'; ++c) {
        letters.emplace(c, Letter());  // Usa emplace() para eficiência
    }
}

// Método para definir a frequência de uma letra
void ReadingCipher::setFrequency(char letter, int freq) {
    if (letters.find(letter) != letters.end()) {
        letters[letter].Frequency = freq;
    }
}

// Método para exibir as frequências armazenadas
void ReadingCipher::printFrequencies() {
    for (const auto& pair : letters) {
        cout << "Letra: " << pair.first << " - Frequência: " << pair.second.Frequency << endl;
    }
}

int main() {
    ReadingCipher cipher('Pm ol ohk hufaopun jvumpkluaphs av zhf, ol dyval pa pu jpwoly, aoha pz, if zv johunpun aol vykly vm aol slaalyz vm aol hswohila, aoha uva h dvyk jvbsk il thkl vba.');  // Criando um objeto da classe

    
    // Exibindo as frequências
    cipher.printFrequencies();

    return 0;
}
