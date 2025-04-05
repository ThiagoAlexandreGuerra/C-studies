#ifndef POLIGONO_H  // Correção na diretiva de inclusão
#define POLIGONO_H

class Poligono {  // Nome da classe deve ser o mesmo em todos os arquivos

private:
    int numLados;  // Nome das variáveis deve ser consistente
    float tamLado;

public:
    Poligono(int lados, float tamanho);  // Construtor
    float area();
    float perimetro();
    float angInterno();
};

#endif
