class Solution {
    void solve(int open, int close, int &n, string &output, vector<string> &ans){
        if(output.size() == 2 * n){
            ans.push_back(output);
            return;
        }
        if(open < n){
            output.push_back('(');
            solve(open + 1, close, n, output, ans);
            output.pop_back();
        }
        if(close < open){
            output.push_back(')');
            solve(open, close + 1, n, output, ans);
            output.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string output = "";
        solve(0, 0, n, output, ans);
        return ans;
    }
};

//* Time Complexity: O(2^n) in the worst case, as we are generating all possible combinations of parentheses.
//* Space Complexity: O(n) for the recursive stack space, and O(2^n) for storing the generated combinations in the answer vector.