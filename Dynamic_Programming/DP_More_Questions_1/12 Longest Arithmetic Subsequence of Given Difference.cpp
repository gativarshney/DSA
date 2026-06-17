//**** DP with hashing */

//! Optimized Solution using Hashing
//?************************************************* THis is DP on values
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        unordered_map<int, int> dp;
        int ans = 1;

        for(int i = 0; i < n; i++){
            int temp = arr[i] - difference;
            int tempAns = 0;

            if(dp.count(temp)){
                tempAns = dp[temp];
            }

            dp[arr[i]] = 1 + tempAns;

            ans = max(ans, dp[arr[i]]);
        }

        return ans;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)

//! here in this problem our dp does not depends on the index, it depends on the value of the element. So we can use hashing to store the dp values for each element and get the answer in O(n) time and O(n) space.


//! This Solution gave Memoery Limit Exceeded error. 
//?************ THis is DP on indices
class Solution {
    int solve(int idx, int prevIdx, int &diff, vector<int> &arr, vector<vector<int>> &dp){
        if(idx >= arr.size()) return 0;

        if(dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];

        int notTake = solve(idx + 1, prevIdx, diff, arr, dp);

        int take = 0;
        if((prevIdx == -1) || (arr[idx] - arr[prevIdx] == diff)){
            take = 1 + solve(idx + 1, idx, diff, arr, dp);
        }

        return dp[idx][prevIdx + 1] = max(take, notTake);
    }
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return solve(0, -1, difference, arr, dp);
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(n^2) + O(n)