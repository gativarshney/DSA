//! Recusrion + Memoization
const int MOD = 1e9 + 7;
int f(int idx, int sum, vector<int>&arr, vector<vector<int>>&dp){
	if(idx == 0) {
		if(sum == 0 && arr[0] == 0) return 2;   
		if(sum == 0 || arr[0] == sum) return 1; 
		return 0;
	}
	if(dp[idx][sum] != -1) return dp[idx][sum];

	int notTake = f(idx-1, sum, arr, dp);
	int take = 0;
	if(arr[idx] <= sum) take = f(idx-1, sum-arr[idx], arr, dp);
	return dp[idx][sum] = (take + notTake) % MOD;
}
int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return f(n-1, k, arr, dp);
}
// Time Complexity: O(N*K) where N is the size of the array and K is the target sum.
// Space Complexity: O(N*K) for the dp array and O(N) for the recursion

// when sum is 0 and arr[0] is also 0, we have two options, either we take the element or we don't take the element. So we have two subsets, one is empty subset and another is subset with the element 0. So we return 2 in this case.
// when sum is 0, we have one subset which is empty subset. So we return 1 in this case. And when arr[0] is equal to sum, we have one subset which is the subset with the element arr[0]. So we return 1 in this case.

//! Tabulation
const int MOD = 1e9 + 7;
int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	if(arr[0] == 0) dp[0][0] = 2;
	else dp[0][0] = 1;
	if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1; 
	for(int idx=1; idx<n; idx++){
		for(int sum=0; sum<=k; sum++){
			int notTake = dp[idx-1][sum];
			int take = 0;
			if(arr[idx] <= sum) take = dp[idx-1][sum-arr[idx]];
			dp[idx][sum] = (take + notTake) % MOD;
		}
	}
	return dp[n-1][k];
}
// Time Complexity: O(N*K) where N is the size of the array and K is the target sum.
// Space Complexity: O(N*K) for the dp array.

//! Space Optimization
const int MOD = 1e9 + 7;
int findWays(vector<int>& arr, int k){
	int n = arr.size();
	vector<int> prev(k+1, 0), curr(k+1, 0);
	if(arr[0] == 0) prev[0] = 2;
	else prev[0] = 1;
	if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1; 
	for(int idx=1; idx<n; idx++){
		for(int sum=0; sum<=k; sum++){
			int notTake = prev[sum];
			int take = 0;
			if(arr[idx] <= sum) take = prev[sum-arr[idx]];
			curr[sum] = (take + notTake) % MOD;
		}
		prev = curr;
	}
	return prev[k];
}
// Time Complexity: O(N*K) where N is the size of the array and K is the target sum.
// Space Complexity: O(K) for the prev and curr arrays.