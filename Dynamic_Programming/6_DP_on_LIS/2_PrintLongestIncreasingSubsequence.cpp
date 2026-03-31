vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	vector<int> dp(n, 1), hash(n);
	for(int i=0; i<n; i++) hash[i] = i;
	int maxi = INT_MIN;
	int lastIndex = 0;
	for(int idx=0; idx<n; idx++){
		for(int prev=0; prev<idx; prev++){
			if(arr[prev] < arr[idx]){
				if(dp[idx] < 1 + dp[prev]){
					dp[idx] = 1 + dp[prev];
					hash[idx] = prev;
				}
			}
			if(maxi < dp[idx]){
				maxi = dp[idx];
				lastIndex = idx;
			}
		}
	}
	vector<int> lis(maxi);
	lis[0] = arr[lastIndex];
	int idx = 1;
	while(hash[lastIndex] != lastIndex){
		lastIndex = hash[lastIndex];
		lis[idx++] = arr[lastIndex];
	}
	reverse(lis.begin(), lis.end());
	return lis;
}
// Time Complexity: O(n^2)
// Space Complexity: O(n) for dp and hash arrays, O(n) for the longest increasing subsequence array.

//* It is done using backtracking, we store the previous index in the hash array and backtrack to find the actual sequence. We also keep track of the maximum length of the increasing subsequence and its last index to start backtracking from there.