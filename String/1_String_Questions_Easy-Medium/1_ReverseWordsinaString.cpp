class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = n-1;
        string ans = "";
        while(i >= 0){
            string word = "";
            while(i >= 0 && s[i] == ' ') i--;
            if(i != -1 && !ans.empty()) ans += ' ';
            while(i >= 0 && s[i] != ' '){
                word.push_back(s[i]);
                i--;
            }
            reverse(word.begin(), word.end());
            ans = ans + word;
        }
        return ans;
    }
};