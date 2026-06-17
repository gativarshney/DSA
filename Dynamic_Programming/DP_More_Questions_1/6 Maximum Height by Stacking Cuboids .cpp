class Solution {
    bool check(vector<int> &curr, vector<int> &prev){
        if(curr[0] <= prev[0] && curr[1] <= prev[1] && curr[2] <= prev[2]) return true;
        return false;
    }

    int solve(int idx, int prevIdx, vector<vector<int>> &cuboids, vector<vector<int>> &dp){
        if(idx == cuboids.size()) return 0;

        if(dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];

        int take = 0;
        int notTake = solve(idx + 1, prevIdx, cuboids, dp);

        if(prevIdx == -1 || check(cuboids[idx], cuboids[prevIdx])){
            take = cuboids[idx][2] + solve(idx + 1, idx, cuboids, dp);
        }

        return dp[idx][prevIdx + 1] = max(take, notTake);
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        for(auto &a : cuboids){
            sort(a.begin(), a.end());
        }

        sort(cuboids.begin(), cuboids.end(), greater<vector<int>>());

        return solve(0, -1, cuboids, dp);
    }
};
// Time Complexity: O(n^2) + O(nlogn)
// Space Complexity: O(n^2) + O(n)