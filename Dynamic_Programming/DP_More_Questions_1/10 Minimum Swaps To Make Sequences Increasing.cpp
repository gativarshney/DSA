class Solution {
    int solve(int idx, bool swappedPrev, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp){
        if(idx == nums1.size()) return 0;

        if(dp[idx][swappedPrev] != -1) return dp[idx][swappedPrev];

        int ans = 1e9;
        int prev1 = nums1[idx - 1];
        int prev2 = nums2[idx - 1];

        if(swappedPrev){
            swap(prev1, prev2);
        }
        // no swap
        if(nums1[idx] > prev1 && nums2[idx] > prev2){
            ans = min(ans, solve(idx + 1, 0, nums1, nums2, dp));
        }
        // swap
        if(nums1[idx] > prev2 && nums2[idx] > prev1){
            ans = min(ans, 1 + solve(idx + 1, 1, nums1, nums2, dp));
        }

        return dp[idx][swappedPrev] = ans;
    }
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();

        bool swappedPrev = false;
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solve(1, swappedPrev, nums1, nums2, dp);
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n) + O(n) for dp array and recursion stack.

//! Tabulation
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();

        vector<vector<int>> dp(n+1, vector<int>(2, 0));

        for(int idx = n-1; idx >= 1; idx--){
            for(int swappedPrev = 1; swappedPrev >= 0; swappedPrev--){
                
                int ans = 1e9;
                int prev1 = nums1[idx - 1];
                int prev2 = nums2[idx - 1];

                if(swappedPrev){
                    swap(prev1, prev2);
                }
                if(nums1[idx] > prev1 && nums2[idx] > prev2){
                    ans = min(ans, dp[idx+1][0]);
                }
                if(nums1[idx] > prev2 && nums2[idx] > prev1){
                    ans = min(ans, 1 + dp[idx+1][1]);
                }

                dp[idx][swappedPrev] = ans;
            }
        }

        return dp[1][0];
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n) for dp array.

//! Space Optimization
class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        int n = nums1.size();

        int nextSwapped = 0;
        int nextNotSwapped = 0;
        int currSwapped = 0;
        int currNotSwapped = 0;

        for(int idx = n-1; idx >= 1; idx--){
            for(int swappedPrev = 1; swappedPrev >= 0; swappedPrev--){

                int ans = 1e9;
                int prev1 = nums1[idx - 1];
                int prev2 = nums2[idx - 1];

                if(swappedPrev){
                    swap(prev1, prev2);
                }
                if(nums1[idx] > prev1 && nums2[idx] > prev2){
                    ans = min(ans, nextNotSwapped);
                }
                if(nums1[idx] > prev2 && nums2[idx] > prev1){
                    ans = min(ans, 1 + nextSwapped);
                }

                if(swappedPrev) currSwapped = ans;
                else currNotSwapped = ans;
            }
            nextSwapped = currSwapped;
            nextNotSwapped = currNotSwapped;
        }

        return nextNotSwapped;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)
