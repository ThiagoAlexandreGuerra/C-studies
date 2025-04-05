#include <iomanip>
#include <iostream>

using namespace std; 

int fibonatti(int n){

    if(n==0){
        return n;
    }

    if(n==1){
        return 1;
    }
    
    return fibonatti(n-1)+fibonatti(n-2);
    
}

int main(){

    cout<<"fibonatti: "<<fibonatti(4);
    
    return 0;
}