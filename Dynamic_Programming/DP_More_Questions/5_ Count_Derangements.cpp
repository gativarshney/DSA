#include<bits/stdc++.h>
using namespace std;
long long int solve(int n, vector<long long int> &dp){
    if(n == 1) return 0;
    if(n == 2) return 1;
    if(dp[n] != -1) return dp[n];
    long long int ans = (n-1) * (solve(n-1, dp) + solve(n-2, dp));
    long long int mod = 1e9 + 7;
    return dp[n] = ans % mod;
}
long long int countDerangements(int n) {
    vector<long long int> dp(n+1, -1);
    long long int result = solve(n, dp);
    return result;
}
// Time Complexity: O(n) where n is the input number.
// Space Complexity: O(n) for the dp array and O(n) for the recursion stack

//! Tabulation
#include<bits/stdc++.h>
using namespace std;
long long int countDerangements(int n) {
    vector<long long int> dp(n+1, 0);
    long long int mod = 1e9 + 7;
    dp[1] = 0, dp[2] = 1;
    for(int i=3; i<=n; i++){
        long long int ans = (i-1) * (dp[i-1] + dp[i-2]);
        long long int mod = 1e9 + 7;
        dp[i] = ans % mod;
    }
    return dp[n];
}
// Time Complexity: O(n) where n is the input number.
// Space Complexity: O(n) for the dp array.

//! Space Optimization
#include<bits/stdc++.h>
using namespace std;
long long int countDerangements(int n) {
    long long int mod = 1e9 + 7;
    long long int prev2 = 0, prev1 = 1;
    for(int i=3; i<=n; i++){
        long long int curr = ((i-1) * (prev1 + prev2)) % mod;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
// Time Complexity: O(n) where n is the input number.


// Space Complexity: O(1)

//* Function is (n-1) * (f(n-1) + f(n-2)) where f(n) is the number of derangements for n items.
//* This is because for the first item, we have (n-1) choices to place it in a wrong position. After placing the first item, we have two cases:
//* Case 1: The other item is swapped with the first item, which contributes f(n-2) derangements.
//* Case 2: The other item is not swapped with the first item, which contributes f(n-1) derangements. 
//* Hence, the total number of derangements is (n-1) * (f(n-1) + f(n-2)).