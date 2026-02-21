int solve(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if(day == 0){
        int maxi = 0;
        for(int task=0; task<3; task++){
            if(task != last){
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last] != -1) return dp[day][last];
    int maxi = 0;
    for(int task=0; task<3; task++){
        if(task != last){
            int point = points[day][task] + solve(day-1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    dp[day][last] = maxi;
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return solve(n-1, 3, points, dp);

}
//* TC: O(n × 4 × 3) ≈ O(n)
//* SC: O(n × 4) + O(n) recursion stack


/*
NINJA TRAINING — IMPORTANT NOTES

State:
solve(day, last) = max points till 'day' if previous day's task was 'last'

task = today's choice, last = yesterday's task

Never use points[day][last] inside loop.
Use points[day][task].

last = 3 means no restriction.
*/

//! point = points[day][task] + solve(day-1, task, points, dp); --> means “If I choose task today, what total points can I get?”
// 📌 Meaning of Each Part

// 🔹 points[day][task]
// 👉 Points earned TODAY by doing this task

// 🔹 solve(day-1, task, ...)
// 👉 Best points from previous days
// 👉 Given that yesterday’s task was task


//! Tabular Method
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int> (4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1; day<n; day++){
        for(int last=0; last<4; last++){
            dp[day][last] = 0;
            for(int task=0; task<3; task++){
                if(task != last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n-1][3];
}
//* TC: O(n × 4 × 3) ≈ O(n)
//* SC: O(n × 4)

//! Space Optimization
int ninjaTraining(int n, vector<vector<int>> &points){
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1; day<n; day++){
        vector<int> temp(4, 0);
        for(int last=0; last<4; last++){
            temp[last] = 0;
            for(int task=0; task<3; task++){
                if(task != last){
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}
//* TC: O(n × 4 × 3) ≈ O(n) 
//* SC: O(4) = O(1)