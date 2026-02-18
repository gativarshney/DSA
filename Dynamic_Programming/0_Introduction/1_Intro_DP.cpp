//? DP : Recursion → Memoization → Tabulation → Space Optimization
//* Memoization : Top Down Approach
//* Tabulation : Bottom Up Approach

//! Using Recursion & Memoization to solve Fibonacci Number
#include<bits/stdc++.h>
using namespace std;

int dp_fib(int n, vector<int> &dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    return dp[n] = dp_fib(n-1, dp) + dp_fib(n-2, dp);
}

int main(){
    int n;
    cout << "Enter n for fib(n): ";
    cin >> n;
    vector<int> dp(n+1, -1);
    int ans = dp_fib(n, dp);
    cout << "Answer : " << ans << endl;
}
// Time Complexity : O(n) 
// Space Complexity : O(n) for recursion stack + O(n) for dp array = O(n) in case of memorization

//! Tabulation Code

dp[0] = 0;
dp[1] = 1;
for(int i=2; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2];
}
// Time Complexity : O(n)
// Space Complexity : O(n) for dp array = O(n) in case of tabulation
// Eliminated the space complexity of recursion stack in case of tabulation

//! Space Optimization
int prev2 = 0, prev = 1;
for(int i=2; i<=n; i++){
    int curi = prev + prev2;
    prev2 = prev;
    prev = curi;
}
return prev;

// Time Complexity: O(n)
// Space Complexity: O(1) 