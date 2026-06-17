class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();

        sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b){
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        int ans = 1;
        int lastEnd = pairs[0][1];

        for(int i = 1; i < n; i++){

            int currStart = pairs[i][0];
            int currEnd = pairs[i][1];

            if(currStart > lastEnd){
                ans++;
                lastEnd = currEnd;
            }
            
        }

        return ans;
    }
};