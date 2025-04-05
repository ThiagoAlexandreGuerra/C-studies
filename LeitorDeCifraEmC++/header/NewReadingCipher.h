#ifndef NEWREADINGCIPHER_H
#define NEWREADINGCIPHER_H

struct Letter{

    int Frequency;
    double Percent;
    char L;
    int* Positions;
    int length;


    Letter(int len = 0) : Frequency(0), Percent(0),length(len), Positions(nullptr) {
        if (length > 0) {
            Positions = new int[length];  
        }
    }

    ~Letter() {
        delete[] Positions;  
    }

    void filled(int position, int index) {
        if (Positions != nullptr && index >= 0 && index < length) { 
            Positions[index] = position;
        }
    }
};


class NewReadingCipher{

    private:
        char UserCipher;
        Letter LetterCipher;

    public:
        void LetterAlocation(char UserCipher); 
        
};


#endif