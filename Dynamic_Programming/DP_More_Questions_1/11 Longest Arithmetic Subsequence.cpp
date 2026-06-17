//! Brute Force
class Solution {
    int solve(int i, int diff, vector<int> &nums){
        if(i < 0) return 0;

        int ans = 0;
        // backward traversal to find the previous element in the arithmetic sequence with the same difference
        for(int j = i - 1; j >= 0; j--){
            if(nums[i] - nums[j] == diff){
                ans = max(ans, 1 + solve(j, diff, nums));
            }
        }

        return ans;
    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) return n;

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int diff = nums[j] - nums[i];
                ans = max(ans, 2 + solve(i, diff, nums));   // +2 to include the current element and the previous element in the arithmetic sequence
            }
        }

        return ans;
    }
};
// Time Complexity: O(n^3)
// Space Complexity: O(n) for recursion stack.

//! DP with Memoization (Using Hashing)
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        if(n <= 2) return n;

        int ans = 0;
        unordered_map<int, int> dp[n + 1];

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){

                int diff = nums[i] - nums[j];
                int cnt = 1;
                
                if(dp[j].count(diff)){
                    cnt = dp[j][diff];
                }

                dp[i][diff] = 1 + cnt;
                ans = max(ans, dp[i][diff]);
            }
        }

        return ans;
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n^2) for dp array.