class Solution {
private:
    void solve(int idx, string digits, vector<string> &ans, string output, vector<string>&mapping){
        if(idx >= digits.size()){
            ans.push_back(output);
            return;
        }
        int number = digits[idx] - '0';
        string str = mapping[number - 2];
        for(int i=0; i<str.size(); i++){
            output.push_back(str[i]);
            solve(idx+1, digits, ans, output, mapping);
            output.pop_back();A
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        string output = "";
        vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(0, digits, ans, output, mapping);
        return ans;
    }
};