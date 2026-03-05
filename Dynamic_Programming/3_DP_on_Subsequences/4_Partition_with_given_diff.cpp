class Solution {
private:
    const int MOD = 1e9 + 7;
    int findWays(int idx, int sum, vector<int>&arr, vector<vector<int>>&dp){
    	if(idx == 0) {
    		if(sum == 0 && arr[0] == 0) return 2;   
    		if(sum == 0 || arr[0] == sum) return 1; 
    		return 0;
    	}
    	if(dp[idx][sum] != -1) return dp[idx][sum];
    
    	int notTake = findWays(idx-1, sum, arr, dp);
    	int take = 0;
    	if(arr[idx] <= sum) take = findWays(idx-1, sum-arr[idx], arr, dp);
    	return dp[idx][sum] = (take + notTake) % MOD;
    }
public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int total = 0;
        for(int i=0; i<n; i++){
            total += arr[i];
        }
        vector<vector<int>> dp(n, vector<int>(total+1, -1));
        if (total < diff) return 0;
        if ((total + diff) % 2 != 0) return 0;
        int target = (total + diff) / 2;
        int cnt = findWays(n-1, target, arr, dp);
        return cnt;
    }
};
// Time Complexity: O(N*total) where N is the size of the array and total is the sum of all elements in the array.
// Space Complexity: O(N*total) for the dp array and O(N) for the recursion stack.

// Logic:
// The problem can be reduced to finding the count of subsets with a given sum.
// Let the two subsets be S1 and S2. We need to find the count of subsets S1 such that:
// sum(S1) - sum(S2) = diff
// sum(S1) + sum(S2) = total
// Solving these two equations gives us:
// sum(S1) = (total + diff) / 2
// Therefore, we need to find the count of subsets with sum equal to (total + diff) / 2.