class Solution {
public:
    int countRev (string s) {
        int n = s.size();
        if(n % 2 == 1) return -1;

        int open = 0;
        int close = 0;

        for(char &it : s){
            if(it == '(') open++;
            else{
                if(open > 0) open--;
                else close++;
            }
        }

        if((open + close) % 2 != 0) return -1;

        int ans = (open / 2) + (open % 2) + (close / 2) + (close % 2);

        return ans;
    }
};

//* TC: O(N) SC: O(1)