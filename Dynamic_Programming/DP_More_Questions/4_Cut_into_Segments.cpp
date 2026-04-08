//! Recursive Solution
int solve(int n, int x, int y, int z){
	if(n == 0) return 0;
	if(n < 0) return -1e9;
	int a = 1 + solve(n-x, x, y, z);
	int b = 1 + solve(n-y, x, y, z);
	int c = 1 + solve(n-z, x, y, z);
	return max(a, max(b, c));
}
int cutSegments(int n, int x, int y, int z) {
	int ans = solve(n, x, y, z);
	if(ans < 0) return 0;
	return ans;
}
// Time Complexity: O(3^n) where n is the input number.
// Space Complexity: O(n) for the recursion stack.

//! Using Memoization
#include<bits/stdc++.h>
using namespace std;
int solve(int n, int x, int y, int z, vector<int> &dp){
	if(n == 0) return 0;
	if(n < 0) return -1e9;
	if(dp[n] != -1) return dp[n];	
	int a = 1 + solve(n-x, x, y, z, dp);
	int b = 1 + solve(n-y, x, y, z, dp);
	int c = 1 + solve(n-z, x, y, z, dp);
	return dp[n] = max(a, max(b, c));
}
int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, -1);
	int ans = solve(n, x, y, z, dp);
	if(ans < 0) return 0;
	return ans;
}
// Time Complexity: O(n) where n is the input number.
// Space Complexity: O(n) for the dp array and O(n) for the recursion stack.

//! Tabulation
int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1, -1e9);
	dp[0] = 0;
	for(int i=0; i<=n; i++){
		if(i-x >=0) dp[i] = max(dp[i], 1 + dp[i-x]);
		if(i-y >=0) dp[i] = max(dp[i], 1 + dp[i-y]);
		if(i-z >=0) dp[i] = max(dp[i], 1 + dp[i-z]);
	}
	int ans = dp[n];
	if(ans < 0) return 0;
	return ans;
}
// Time Complexity: O(n) where n is the input number.
// Space Complexity: O(n) for the dp array.