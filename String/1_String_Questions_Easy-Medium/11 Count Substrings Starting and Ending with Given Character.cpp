class Solution {
public:
    long long countSubstrings(string s, char c) {

        int m = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == c) m++;
        }

        long long ans = (1LL * m * (m + 1)) / 2;

        return ans;
    }
};

// If len is n then substring can be formed in n * (n + 1) / 2 ways.