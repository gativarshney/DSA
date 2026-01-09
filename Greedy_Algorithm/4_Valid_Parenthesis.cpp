// Valid Parenthesis String
// Given a string containing only three types of characters: '(', ')' and '*',

class Solution {
private: 
    bool check(string s, int idx, int cnt){
        if(cnt < 0) return false;
        if(idx == s.size()) return (cnt == 0);
        if(s[idx] == '(') return check(s, idx+1, cnt+1);
        if(s[idx] == ')') return check(s, idx+1, cnt-1);
        return check(s, idx+1, cnt+1) || check(s, idx+1, cnt-1) || check(s, idx+1, cnt);
    }
public:
    bool checkValidString(string s) {
        return check(s, 0, 0);
    }
};
//* Time Complexity: O(3^n) in worst case
//* Space Complexity: O(n) for recursion stack

//! *************************************************************************

// Optimized Approach   

class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, maxi = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                mini = mini + 1;
                maxi = maxi + 1;
            }
            else if(s[i] == ')'){
                mini = mini - 1;
                maxi = maxi - 1;
            }
            else{
                mini = mini - 1;
                maxi = maxi + 1;
            }
            if(mini < 0) mini = 0;
            if(maxi < 0) return false;
        }
        return (mini == 0);
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)


// Approach:
// We use a greedy range-based technique to track the possible balance of parentheses.
// `mini` represents the minimum possible open parentheses count,
// while `maxi` represents the maximum possible open parentheses count at any point.
//
// For '('  → both mini and maxi increase.
// For ')'  → both mini and maxi decrease.
// For '*'  → it can act as '(', ')' or empty, so mini decreases and maxi increases.
//
// We clamp `mini` to 0 since open count cannot be negative.
// If `maxi` ever becomes negative, it means too many ')' appeared → invalid string.
//
// At the end, if `mini` is 0, a valid interpretation exists; otherwise, it does not.

