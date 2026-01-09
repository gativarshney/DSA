// Rightmost
#include<bits/stdc++.h>
using namespace std;

int removeLastSetBit(int n){
    return n & n-1;
}

int main(){
    cout << removeLastSetBit(102);
    return 0;
}