//! Using Longest Increasing Subsequence (LIS) approach (Binary Search)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](const auto &a, const auto &b){
            if(a[0] == b[0]) return a[1] > b[1];
            return a < b;
        });

        vector<int> temp;
        temp.push_back(envelopes[0][1]);

        for(int i = 1; i < n; i++){

            int h = envelopes[i][1];

            if(h > temp.back()){
                temp.push_back(h);
            }
            else{
                int idx = lower_bound(temp.begin(), temp.end(), h) - temp.begin();
                temp[idx] = h;
            }
        }

        return temp.size();
    }
};
// Time Complexity: O(n log n) due to sorting and binary search
// Space Complexity: O(n) for the temp vector used in LIS approach

//! NOTE: 
// We sort the envelopes in increasing order of width and in decreasing order of height when widths are the same.
// This prevents LIS from accidentally choosing multiple envelopes having the same width.


//! Intuition:
// Sort width ASC.
// For same width, sort height DESC.
//
// Why?
// Same-width envelopes cannot be nested.
// If heights were ASC, LIS could incorrectly pick
// multiple envelopes having the same width.
// Sorting heights DESC makes equal-width envelopes
// appear as a decreasing sequence, so LIS can take
// at most one of them.