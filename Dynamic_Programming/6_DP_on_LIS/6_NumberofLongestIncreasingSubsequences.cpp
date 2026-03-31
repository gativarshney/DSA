 class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 0;
        for(int idx=0; idx<n; idx++){
            for(int prev=0; prev<idx; prev++){
                if(nums[idx] > nums[prev] && dp[idx] < dp[prev] + 1){
                    dp[idx] = dp[prev] + 1;
                    cnt[idx] = cnt[prev];
                }
                else if(nums[idx] > nums[prev] && dp[idx] == dp[prev] + 1){
                    cnt[idx] = cnt[idx] + cnt[prev];
                }
            }
            maxi = max(maxi, dp[idx]);
        }
        int nos = 0;
        for(int i=0; i<n; i++){
            if(dp[i] == maxi) nos += cnt[i];
        }
        return nos;
    }
};
// Time Complexity: O(N^2)
// Space Complexity: O(N)