//! Recursion + Memoization
class Solution {
    int f(int idx, int time, vector<int> &satisfaction, vector<vector<int>> &dp){
        if(idx == satisfaction.size()) return 0;

        if(dp[idx][time] != -1) return dp[idx][time];

        int notTake = f(idx + 1, time, satisfaction, dp);
        int take = satisfaction[idx] * time + f(idx + 1, time + 1, satisfaction, dp);

        return dp[idx][time] = max(take, notTake);
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return f(0, 1, satisfaction, dp);
    }
};
// TC: O(n*n) due to 2 nested loops and n is the length of the satisfaction array
// SC: O(n*n) for the dp array + O(n) for the recursion stack

//! Tabulation
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+2, 0));

        sort(satisfaction.begin(), satisfaction.end());

        for(int idx = n-1; idx >= 0; idx--){
            for(int time = n; time >= 0; time--){

                int notTake = dp[idx + 1][time];
                int take = satisfaction[idx] * time + dp[idx + 1][time + 1];

                dp[idx][time] = max(take, notTake);
            }
        }

        return dp[0][1];
    }
};
// TC: O(n*n) due to 2 nested loops and n is the length of the satisfaction array
// SC: O(n*n) for the dp array

//! Space Optimization
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        vector<int> curr(n+2, 0);
        vector<int> next(n+2, 0);

        sort(satisfaction.begin(), satisfaction.end());

        for(int idx = n-1; idx >= 0; idx--){
            for(int time = n; time >= 0; time--){

                int notTake = next[time];
                int take = satisfaction[idx] * time + next[time + 1];

                curr[time] = max(take, notTake);
            }
            next = curr;
        }

        return next[1];
    }
};
// TC: O(n*n) due to 2 nested loops and n is the length of the satisfaction array
// SC: O(n) for the curr and next arrays

//! Greedy Approach
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();

        sort(satisfaction.begin(), satisfaction.end());

        int suffixSum = 0;
        int ans = 0;
        
        for(int i = n-1; i >= 0; i--){
            suffixSum += satisfaction[i];

            if(suffixSum <= 0) break;
            else ans += suffixSum;
        }

        return ans;
    }
};
// TC: O(nlogn) due to sorting the satisfaction array
// SC: O(1) for the suffixSum and ans variables

//! Intution:
// Score can be viewed as the sum of all suffix sums:
// (a1+...+ak) + (a2+...+ak) + ... + ak
//
// Traverse from right to left and maintain suffixSum.
// If suffixSum > 0, it contributes positively to the answer.
// Once suffixSum <= 0, further elements can only decrease it,
// so stop. 