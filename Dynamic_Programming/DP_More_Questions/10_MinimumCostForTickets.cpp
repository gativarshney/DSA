//! Recusrive
class Solution {
    int solve(int idx, vector<int> &days, vector<int> &costs){
        int n = days.size();
        if(idx >= n){
            return 0;
        }
        int option1 = costs[0] + solve(idx+1, days, costs);
        int i;
        for(i = idx; i<n && days[i] < days[idx] + 7; i++);
        int option2 = costs[1] + solve(i, days, costs);

        for(i = idx; i<n && days[i] < days[idx] + 30; i++);
        int option3 = costs[2] + solve(i, days, costs);

        return min(option1, min(option2, option3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solve(0, days, costs);
    }
};
// TLE for large test cases
// Time Complexity: O(n * 3^n) where n is the number of days in the input vector days   
// Space Complexity: O(n) where n is the number of days in the input vector days due to recursive stack space

//! Memoization
class Solution {
    int solve(int idx, vector<int> &days, vector<int> &costs, vector<int> &dp){
        int n = days.size();
        if(idx >= n){
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int option1 = costs[0] + solve(idx+1, days, costs, dp);
        int i;
        for(i = idx; i<n && days[i] < days[idx] + 7; i++);
        int option2 = costs[1] + solve(i, days, costs, dp);

        for(i = idx; i<n && days[i] < days[idx] + 30; i++);
        int option3 = costs[2] + solve(i, days, costs, dp);

        return dp[idx] = min(option1, min(option2, option3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, -1);
        return solve(0, days, costs, dp);
    }
};
// Time Complexity: O(n*n) where n is the number of days in the input vector days due to memoization
// Space Complexity: O(n) where n is the number of days in the input vector days due to recursive stack space and dp array

//! Tabulation
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, INT_MAX);
        dp[n] = 0;
        for(int idx = n-1; idx >= 0; idx--){
            int option1 = costs[0] + dp[idx+1];
            int i;
            for(i = idx; i<n && days[i] < days[idx] + 7; i++);
            int option2 = costs[1] + dp[i];

            for(i = idx; i<n && days[i] < days[idx] + 30; i++);
            int option3 = costs[2] + dp[i];

            dp[idx] = min(option1, min(option2, option3));
        }
        return dp[0];
    }
};
// Time Complexity: O(n*n) where n is the number of days in the input vector days due to tabulation   
// Space Complexity: O(n) where n is the number of days in the input vector days due to dp array