class Solution {
    int expand(string &s, int l, int r){
        int n = s.size();
        int cnt = 0;

        while(l >= 0 && r < n && s[l] == s[r]){
            cnt++;
            l--;
            r++;
        }

        return cnt;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            count += expand(s, i, i) + expand(s, i, i + 1);
        }

        return count;
    }
};

//* TC: O(N^2) SC: O(1)