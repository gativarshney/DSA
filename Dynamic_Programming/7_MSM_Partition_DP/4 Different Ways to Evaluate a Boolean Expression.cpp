//! Recursive + Memoization
#include <vector>
#include <string>

using namespace std;

long long f(int i, int j, int isTrue, string &s, vector<vector<vector<long long>>> &dp) {
    long long mod = 1e9 + 7;
    
    if (i > j) return 0;

    if (i == j) {
        if (isTrue) return s[i] == 'T';
        else return s[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    long long ways = 0;
    
    for (int idx = i + 1; idx <= j - 1; idx += 2) {
        long long lT = f(i, idx - 1, 1, s, dp); 
        long long lF = f(i, idx - 1, 0, s, dp); 
        long long rT = f(idx + 1, j, 1, s, dp); 
        long long rF = f(idx + 1, j, 0, s, dp); 

        if (s[idx] == '&') {
            if (isTrue) {
                ways = (ways + (lT * rT) % mod) % mod;
            } else {
                ways = (ways + (lT * rF) % mod) % mod;
                ways = (ways + (lF * rT) % mod) % mod;
                ways = (ways + (lF * rF) % mod) % mod;
            }
        }
        else if (s[idx] == '|') {
            if (isTrue) {
                ways = (ways + (lT * rF) % mod) % mod;
                ways = (ways + (lF * rT) % mod) % mod;
                ways = (ways + (lT * rT) % mod) % mod;
            } else {
                ways = (ways + (lF * rF) % mod) % mod;
            }
        }
        else {
            if (isTrue) {
                ways = (ways + (lT * rF) % mod) % mod;
                ways = (ways + (lF * rT) % mod) % mod;
            } else {
                ways = (ways + (lF * rF) % mod) % mod;
                ways = (ways + (lT * rT) % mod) % mod;
            }
        }
    }

    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return f(0, n - 1, 1, exp, dp);
}

//* Time Complexity: O(N^3) where N is the length of the expression. This is because we are using three nested loops to calculate the number of ways. {i, j (in recursive calls) and idx}
//* Space Complexity: O(N^2) for the dp array and O(N) for the recursive call stack, resulting in O(N^2) overall.

//! Tabulation
#include <vector>
#include <string>

using namespace std;

int evaluateExp(string &exp) {
    int n = exp.size();
    long long mod = 1e9 + 7;
    
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, 0)));

    for (int i = n - 1; i >= 0; i -= 2) {
        for (int j = i; j < n; j += 2) {
            if (i == j) {
                dp[i][j][1] = (exp[i] == 'T');
                dp[i][j][0] = (exp[i] == 'F');
                continue;
            }

            long long waysTrue = 0;
            long long waysFalse = 0;

            for (int idx = i + 1; idx <= j - 1; idx += 2) {
                long long lT = dp[i][idx - 1][1];
                long long lF = dp[i][idx - 1][0];
                long long rT = dp[idx + 1][j][1];
                long long rF = dp[idx + 1][j][0];

                if (exp[idx] == '&') {
                    waysTrue = (waysTrue + (lT * rT) % mod) % mod;
                    waysFalse = (waysFalse + (lT * rF) % mod + (lF * rT) % mod + (lF * rF) % mod) % mod;
                } 
                else if (exp[idx] == '|') {
                    waysTrue = (waysTrue + (lT * rF) % mod + (lF * rT) % mod + (lT * rT) % mod) % mod;
                    waysFalse = (waysFalse + (lF * rF) % mod) % mod;
                } 
                else {
                    waysTrue = (waysTrue + (lT * rF) % mod + (lF * rT) % mod) % mod;
                    waysFalse = (waysFalse + (lF * rF) % mod + (lT * rT) % mod) % mod;
                }
            }
            dp[i][j][1] = waysTrue;
            dp[i][j][0] = waysFalse;
        }
    }

    return dp[0][n - 1][1];
}
//* Time Complexity: O(N^3) where N is the length of the expression. This is because we are using three nested loops to calculate the number of ways. {i, j and idx}    
//* Space Complexity: O(N^2) for the dp array.



//! Question: https://www.naukri.com/code360/problems/problem-name-boolean-evaluation_1214650
/**
Different Ways to Evaluate a Boolean Expression

You are given a string expr consisting of the characters

'T' — represents true
'F' — represents false
'&' — the logical AND operator
'|' — the logical OR operator
'^' — the logical XOR (exclusive-or) operator

expr is guaranteed to follow the pattern operand operator operand operator … operand (i.e. it always starts and ends with an operand and no two operators are adjacent).

Return the number of distinct ways to fully parenthesize expr such that the whole expression evaluates to true.
Because the answer can be very large, return it modulo 1e9+7.


Example 1

Input: expr = "T|T&F^T"
Output: 4

Explanation:
The expression can be parenthesized as follows (✓ marks variants that evaluate to true):
1. ((T|T)&(F^T)) ✓
2. (T|(T&(F^T))) ✓
3. (((T|T)&F)^T) ✓
4. (T|((T&F)^T)) ✓
5. ((T|(T&F))^T)   → false
6. (T|T)&F^T     → false
Therefore 4 distinct parenthesizations evaluate to true.

**/