class Solution {
    bool repeat(string &str, string &s){
        int n = s.size();
        int m = str.size();

        if(n % m != 0) return false;

        string temp = str;

        while(str.size() < n){
            str += temp;
        }

        if(str == s) return true;

        return false;

    }
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for(int len = 1; len < n; len++){

            string str = s.substr(0, len);

            if(repeat(str, s)){
                return true;
            }
        }

        return false;
    }
};

// Time: O(n²)
// Space: O(n)