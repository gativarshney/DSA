class Solution {
public:
    string compressedString(string word) {
        int n = word.size();
        string ans = "";

        char prev = word[0];
        int cnt = 1;

        for(int i = 1; i < n; i++){
            char ch = word[i];
            if(ch == prev && cnt < 9){
                cnt++;
            }
            else if(cnt == 9){
                ans += (9 + '0');
                ans += prev;
                cnt = 1;
                prev = ch;
            }
            else{
                ans += (cnt + '0');
                ans += prev;
                prev = ch;
                cnt = 1;
            }
        }

        if(cnt > 0){
            ans += (cnt + '0');
            ans += prev;
        }

        return ans;
    }
};