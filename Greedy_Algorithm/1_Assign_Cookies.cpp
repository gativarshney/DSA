class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int numG = g.size();
        int numS = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int cnt = 0, i = 0, j = 0;
        while(i < numG && j < numS){
            if(g[i] <= s[j]) cnt++, i++, j++;
            else j++;
        }
        return cnt;
    }
};
// Time Complexity: O(nlogn + mlogm + n + m) where n is the size of g and m is the size of s.
// Space Complexity: O(1)