class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        unordered_map<char, int> mpp;

        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;

        int ans = mpp[s[n-1]];

        for(int i = n-2; i >= 0; i--){
            char front = s[i + 1];
            int frontVal = mpp[front];

            char curr = s[i];
            int currVal = mpp[curr];

            if(currVal >= frontVal){
                ans += currVal;
            }
            else{
                ans -= currVal;
            }
        }

        return ans;
    }
};