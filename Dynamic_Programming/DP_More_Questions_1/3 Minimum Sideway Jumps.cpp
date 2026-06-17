class Solution {
    int f(int p, int lane, int n, vector<int> &obstacles, vector<vector<int>> &dp){

        if(p == n-1) return 0;
        if(dp[p][lane] != -1) return dp[p][lane];

        // same lane and no obstacle in the next position
        if(obstacles[p+1] != lane){
            return dp[p][lane] = f(p+1, lane, n, obstacles, dp);
        }

        int minJumps = 1e9;
        // side jumps to other lanes
        for(int j = 1; j <= 3; j++){
            if(j != lane && obstacles[p] != j){
                int jumps = 1 + f(p, j, n, obstacles, dp);
                minJumps = min(minJumps, jumps);
            }
        }

        return dp[p][lane] = minJumps;
    }
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();

        vector<vector<int>> dp(n, vector<int>(4, -1));

        return f(0, 2, n, obstacles, dp);
    }
};
// TC: O(n*3*3) = O(n) due to 3 nested loops and 3 is constant
// SC: O(n*3) for the dp array + O(n) for the recursion stack

//! Tabulation
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();

        vector<vector<int>> dp(n, vector<int>(4, 1e9));
        dp[n-1][1] = 0;
        dp[n-1][2] = 0;
        dp[n-1][3] = 0;

        for(int p = n-2; p >= 0; p--){
            for(int lane = 1; lane <= 3; lane++){

                if(obstacles[p+1] != lane){
                    dp[p][lane] = dp[p+1][lane];
                }
                else{
                    int minJumps = 1e9;
                    for(int j = 1; j <= 3; j++){

                        if(j != lane && obstacles[p] != j){
                            int jumps = 1 + dp[p+1][j]; // I used dp[p+1][j] to avoid reading 1e9 from a lane that hasn't been determined yet so read forward instead of reading dp[p][j]
                            minJumps = min(minJumps, jumps);
                        }

                    }
                    dp[p][lane] = minJumps;
                }
            }
        }

        return min(dp[0][2], min(1 + dp[0][1], 1 + dp[0][3])); // as we can jump from lane 3 -> 2 or lane 1 -> 2 at p = 0 to get minimum jumps, we need to consider those cases as well. We add 1 to the jumps because we are making a side jump at p = 0.
};
//! NOTE: This tabulation solution is a bit tricky to understand, so I recommend drawing the dp table and filling it up to understand the logic behind it. Watch Love Babbar's video for a detailed explanation of the tabulation approach.
// TC: O(n*3*3) = O(n) due to 3 nested loops and 3 is constant
// SC: O(n*3) for the dp array

//! Space Optimization
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();

        vector<int> curr(4, 1e9);
        vector<int> next(4, 1e9);
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int p = n-2; p >= 0; p--){
            for(int lane = 1; lane <= 3; lane++){

                if(obstacles[p+1] != lane){
                    curr[lane] = next[lane];
                }
                else{
                    int minJumps = 1e9;
                    for(int j = 1; j <= 3; j++){

                        if(j != lane && obstacles[p] != j){
                            int jumps = 1 + next[j];
                            minJumps = min(minJumps, jumps);
                        }

                    }
                    curr[lane] = minJumps;
                }
            }
            next = curr;
        }

        return min(next[2], min(1 + next[1], 1 + next[3]));
    }
};
// TC: O(n*3*3) = O(n) due to 3 nested loops and 3 is constant
// SC: O(4) for the curr and next arrays, which is O(1)