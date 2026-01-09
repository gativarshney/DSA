//! Better 
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> mpp;
        for(auto it: nums){
            if(it % 2 == 0) mpp[it]++;
        }

        vector<pair<int, int>> freq(mpp.begin(), mpp.end());        
        sort(freq.begin(), freq.end(), [](const auto& a, const auto& b){
            if(a.second == b.second) return a < b;
            return a.second > b.second;
        });
        if(!freq.empty()) ans = freq[0].first;
        return ans;
    }
};

//* TC: O(n) + O(m) + (m * logm)
//* SC: O(2 * m)
//? m --> unique even elements


//! Optimised
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for(int it: nums) mpp[it]++;
        int maxFreq = 0, ans = -1;
        for(auto it: mpp){
            if(it.first % 2 == 0){
                int freq = it.second;
                if(freq > maxFreq){
                    maxFreq = freq;
                    ans = it.first;
                }
                else if(freq == maxFreq){
                    ans = min(ans, it.first);
                }
            }
        }
        return ans;
    }
};

// TC: O(n)
// SC: O(m)