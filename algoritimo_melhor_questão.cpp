#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace chrono;

//Declaração de constantes**************************************************************************************
//**************************************************************************************************************

#define TDAC 3      //peso taxa de acertos
#define DD 2        // peso da disstancia ate o dia da prova
#define PESD 3      // peso da dificudade
#define PDSIMP 4    //peso da importancia(gral de incidencia da questaão nas ultimas provas)

#define LIN 6       //numero de linhas da matriz
#define CLM 6       //numero de colunas
#define KAM 6       //numeros de camadas

// Declaração de estruturas*************************************************************************************
//**************************************************************************************************************



struct algoritimo_melhor_questao
{
    char nome;
    int id;
    char materia;
    int importancia;
    int dificudade;
    int numero_de_acertos;
    int numero_de_erros;
    int dist_data;
};

// Declaração de funçoes****************************************************************************************
//************************************************************************************************************** 

char time_of_the_system() {
    using chrono::system_clock;
    duration<int, ratio<60*60*24>> one_day(1); 

    system_clock::time_point today = system_clock::now();           //função para atribuir tempo as questôes
    system_clock::time_point tomorrow = today + one_day;            //fuçar depois....
    system_clock::time_point yesterday = today - one_day; 

    time_t tt;

    auto futuro = today + hours(1);
    tt = system_clock::to_time_t(today); 


    
    cout << ctime(&tt) ; 

   return tt;
}

int da_taxa_acertos(int a, int b){

    int taxa_acertos=1;

    taxa_acertos= a/b;
    taxa_acertos=taxa_acertos*100;

    return taxa_acertos;

}

int retorna_numeros_aleatorios(int ale){

    int num=0;

    unsigned seed= time(0);
    srand(ale);
    num= rand()%100;

    return num;
}

int importancia_da_questao(int taxa_de_acertos , int dist_data , int dificudade , int importancia){

    int media= ((taxa_de_acertos*TDAC) + (dist_data*DD) + (dificudade+PESD) + (importancia* PDSIMP))/
                    (TDAC+DD+PESD+PDSIMP);

    return media;                
}
void le_matriz(int matriz[LIN][CLM][KAM]) {
    for (int i = 0; i < LIN; i++) {
        for (int j = 0; j < CLM; j++) {
            for (int k = 0; k <KAM ; k++){

                cout << setw(4) << matriz[i][j][k]; 
            }
            cout<< endl;


        }
        cout << endl;
    }
}

//função principal*******************************************
//*********************************************************** 

int main() {

    int lmt=LIN*CLM*KAM, num=0;
    int matriz[LIN][CLM][KAM];
    string nomes[100]={"conhecimetos", "vendas" , "tecnologia" , "mareting" , "portugues"};

    for(int ct=0 ; ct<lmt ; ct++){


        for(int k = 0; k < KAM ; k++){

            for (int i = 0; i < LIN; i++) {
    
                for (int j = 0; j < CLM; j++) {

                    int a=0 , b=0, data=0 ,dificudade=0 , importancia=0;
                     algoritimo_melhor_questao nomes[k];

                    nomes[k].dificudade= retorna_numeros_aleatorios(k);
                    nomes[k].importancia= retorna_numeros_aleatorios(i);
                    nomes[k].id=retorna_numeros_aleatorios(j)+100;
                    nomes[k].numero_de_acertos=retorna_numeros_aleatorios(ct);
                    nomes[k].numero_de_erros=retorna_numeros_aleatorios(i);
                    nomes[k].dist_data= retorna_numeros_aleatorios(j);

                    a=nomes[k].numero_de_acertos;
                    b=nomes[k].numero_de_erros;
                    data=nomes[k].dist_data;
                    dificudade=nomes[k].dificudade;
                    importancia=nomes[k].importancia;

                    int retorno_func_taxa=0, retorno_func_importancia=0;

                    retorno_func_taxa= da_taxa_acertos(a, b);
                    retorno_func_importancia= importancia_da_questao( retorno_func_taxa , data , dificudade , importancia );

                    
                        cout<<nomes[k].dificudade;
                        cout<<nomes[k].dist_data;
                        cout<<nomes[k].importancia;
                        cout<<nomes[k].dificudade;
                        cout<<nomes[k].dificudade;
                    

                    cout<<"a importancia da questão é "<< retorno_func_importancia<< endl;
                    return 0;

                   // matriz[i][j][k] = i * LIN + j * CLM + k;  
                    matriz[i][j][k] = 0; 

                    if(j==0 && i==0){

                        num = retorna_numeros_aleatorios(k);
                        matriz[k][0][0]= num;
                    }
                }
            }

        }
    }

    

    le_matriz(matriz);

    time_of_the_system(); 
    return 0;
}

