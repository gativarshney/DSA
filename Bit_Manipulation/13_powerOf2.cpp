#include<bits/stdc++.h>
using namespace std;

bool powerOf2(int n){
    if((n > 0) && ((n & n-1) == 0)) return true;
    return false;
}

int main(){
    int num = 1024;
    if(powerOf2(num)){
        cout << "Yupp, power of 2";
    }
    else{
        cout << "Chup kr bc";
    }
    return 0;
}