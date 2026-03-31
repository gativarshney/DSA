class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp1(n, 1), dp2(n, 1);
        for(int idx=0; idx<n; idx++){
            for(int prev=0; prev<idx; prev++){
                if(nums[idx] > nums[prev] && dp1[idx] < dp1[prev] + 1){
                    dp1[idx] = dp1[prev] + 1;
                }
            }
        }
        for(int idx=n-1; idx>=0; idx--){
            for(int prev=n-1; prev>idx; prev--){
                if(nums[idx] > nums[prev] && dp2[idx] < dp2[prev] + 1){
                    dp2[idx] = dp2[prev] + 1;
                }
            }
        }
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i] > 1 && dp2[i] > 1) {
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }
        }
        if(maxi < 3) return 0;
        return maxi;
    }
};
// Time Complexity: O(N^2)
// Space Complexity: O(N)