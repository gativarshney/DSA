class Solution {
    int solve(int idx, int k, int end, vector<int> &slices, vector<vector<int>> &dp){
        if(k == 0) return 0;
        if(idx == end){
            if(k == 1) return slices[idx];
            else return -1e9;
        }
        if(idx > end) return -1e9;

        if(dp[idx][k] != -1) return dp[idx][k];

        int notTake = solve(idx+1, k, end, slices, dp);
        int take = slices[idx] + solve(idx+2, k-1, end, slices, dp);

        return dp[idx][k] = max(take, notTake);
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;

        vector<vector<int>> dp1(n, vector<int>(k+1, -1));
        vector<vector<int>> dp2(n, vector<int>(k+1, -1));

        return max(solve(0, k, n-2, slices, dp1), solve(1, k, n-1, slices, dp2));

    }
};
// Time Complexity: O(n*k) + O(n*k)
// Space Complexity: O(n*k) + O(n*k)

//! Tabulation
class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int kslice = n / 3;

        vector<vector<int>> dp1(n+2, vector<int>(kslice + 1, 0));
        vector<vector<int>> dp2(n+2, vector<int>(kslice + 1, 0));

        for(int idx = n-2; idx >= 0; idx--){
            for(int k = 1; k <= kslice; k++){
                int notTake = dp1[idx+1][k];
                int take = slices[idx] + dp1[idx+2][k-1];

                dp1[idx][k] = max(take, notTake);
            }
        }

        for(int idx = n-1; idx >= 1; idx--){
            for(int k = 1; k <= kslice; k++){
                int notTake = dp2[idx+1][k];
                int take = slices[idx] + dp2[idx+2][k-1];

                dp2[idx][k] = max(take, notTake);
            }
        }

        return max(dp1[0][kslice], dp2[1][kslice]);

    }
};
// Time Complexity: O(n*k) + O(n*k) 
// Space Complexity: O(n*k) + O(n*k)

//* Similar to 198. House Robber, 213. House Robber II, 337. House Robber III, 740. Delete and Earn, 1027. Longest Arithmetic Sequence, 1218. Longest Arithmetic Subsequence of Given Difference, 1563. Stone Game V, 1696. Jump Game VI, 1888. Minimum Number of Flips to Make the Binary String Alternating, 2216. Minimum Deletions to Make Array Beautiful, 2240. Number of Ways to Buy Pens and Pencils, 2244. Minimum Rounds to Complete All Tasks, 2272. Substring With Largest Variance, 2310. Sum of Distances in Tree