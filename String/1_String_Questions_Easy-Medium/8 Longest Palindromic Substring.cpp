class Solution {
    string expand(string &s, int l, int r){

        int n = s.size();

        while(l >= 0 && r < n && s[l] == s[r]){
            l--;
            r++;
        }
        
        int start = l + 1;
        int end = r - 1;
        
        int len = end - start + 1;

        string ans = s.substr(l + 1, len);

        return ans;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        
        for(int i = 0; i < n; i++){

            string str1 = expand(s, i, i);
            string str2 = expand(s, i, i + 1);

            if(str1.size() > ans.size()) ans = str1;
            if(str2.size() > ans.size()) ans = str2;
        }

        return ans;
    }
};

//* TC: O(N^2) SC: O(1)