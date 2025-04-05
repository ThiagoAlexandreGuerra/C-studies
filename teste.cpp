#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct coodenadas{

    int x;
    int y;
};

int distancia_menor_origem( coodenadas a , coodenadas b){
    
    int dist_a=0, dist_b=0;

    coodenadas origem= {0,0};

    dist_a=sqrt(pow(a.x - origem.x, 2) + pow( a.y - origem.y,2));
    dist_b=sqrt(pow(b.x - origem.x, 2) + pow( b.y - origem.y,2));

    if(dist_a>dist_b){
        return b;
    }else{
        return a; 
    }

}

int main(){

    coodenadas vetor[2];
    for(int i=0; i< 2; i++)
        cin>> vetor[i].x >> vetor[i].y;
    
    for(int k=0; k<2; k++){
        dis
    }
    return 0;
}