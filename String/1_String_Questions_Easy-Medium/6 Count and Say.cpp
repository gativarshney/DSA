class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";

        string prev = countAndSay(n-1);

        char ch = prev[0];
        int cnt = 1;
        string curr = "";

        for(int i = 1; i < prev.size(); i++){
            if(prev[i] == ch){
                cnt++;
            }
            else{
                curr += (cnt + '0');
                curr += ch;
                cnt = 1;
                ch = prev[i];
            }
        }
        
        if(cnt > 0){
            curr += (cnt + '0');
            curr += ch;
        }

        return curr;
    }
};
// Time Complexity: O(L), where L is the length of the nth count-and-say string.
// Space Complexity: O(L + n), where O(L) is for the generated string and O(n) is the recursion stack.