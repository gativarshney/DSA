#include<bits/stdc++.h>
using namespace std;

int toggleKthBit_I(int n, int i){
    return n ^ (1 << i);
}
int toggleKthBit_II(int n, int i){
    if(n & (1 << i)){
        return n & (~(1 << i));
    }
    return n | (1 << i);
}
int main(){
    cout << toggleKthBit_I(13, 2); 
    return 0;
}