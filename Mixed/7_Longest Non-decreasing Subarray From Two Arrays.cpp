class Solution {
    int f(int idx, int choice, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp) {
        if(idx == 0) {
            return 1;
        }

        if(dp[idx][choice] != -1) {
            return dp[idx][choice];
        }

        int ans = 1;

        if(choice == 0) {
            if(nums1[idx] >= nums1[idx - 1]) {
                ans = max(ans, 1 + f(idx - 1, 0, nums1, nums2, dp));
            }

            if(nums1[idx] >= nums2[idx - 1]) {
                ans = max(ans, 1 + f(idx - 1, 1, nums1, nums2, dp));
            }
        }
        else {
            if(nums2[idx] >= nums1[idx - 1]) {
                ans = max(ans, 1 + f(idx - 1, 0, nums1, nums2, dp));
            }

            if(nums2[idx] >= nums2[idx - 1]) {
                ans = max(ans, 1 + f(idx - 1, 1, nums1, nums2, dp));
            }
        }

        return dp[idx][choice] = ans;
    }

public:
    int maxNonDecreasingLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        int ans = 1;

        for(int i = 0; i < n; i++) {
            ans = max(ans, f(i, 0, nums1, nums2, dp));
            ans = max(ans, f(i, 1, nums1, nums2, dp));
        }

        return ans;
    }
};