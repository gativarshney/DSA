class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> mpp;
        for(int i : nums) mpp[i]++;
        
        vector<pair<int, int>> freq(mpp.begin(), mpp.end());

        sort(freq.begin(), freq.end(), [](const auto& a, const auto& b){
            return a.second > b.second;
        });
        for(int i=0; i<k; i++){
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};

//* TC: O(2*N) + O(N*logN) + O(k) --> Overall TC: O(N*logN)
//* SC: O(N) + O(N) + O(k) --> Overall SC: O(N)