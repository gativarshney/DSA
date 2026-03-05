//! For array containing only positive numbers
int minSubsetSumDifference(vector<int>& nums, int n){
    int totalSum = 0;
    for(auto it : nums) totalSum += it;
    vector<vector<int>> dp(n, vector<int>(totalSum+1, 0));
    int target = totalSum;
    for(int i=0; i<n; i++) dp[i][0] = true;
    if(nums[0] <= target) dp[0][nums[0]] = true;
    for(int idx=1; idx<n; idx++){
        for(int target=0; target<=totalSum; target++){
            int notTake = dp[idx-1][target];
            int take = false;
            if(nums[idx] <= target) take = dp[idx-1][target-nums[idx]];
            dp[idx][target] = take | notTake;
        }
    }
    int mini = INT_MAX;
    for(int s1=0; s1<=totalSum/2; s1++){
        if(dp[n-1][s1] == true){
            int s2 = totalSum - s1;
            mini = min(mini, abs(s1-s2));
        }
    }
    return mini;
}
// Time Complexity: O(N*totalSum) where N is the size of the array and totalSum is the sum of all elements in the array.
// Space Complexity: O(N*totalSum) for the dp array.