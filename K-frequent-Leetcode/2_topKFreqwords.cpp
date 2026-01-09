//* TC: O(2*N) + O(N*logN*L) + O(k) --> Overall TC: O(N*logN*L) where L is avg string length  
//* SC: O(N) + O(N) + O(k) --> Overall SC: O(N * L) , Because strings take space proportional to their length.

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string, int> mpp;
        for(auto it : words) mpp[it]++;

        vector<pair<string, int>> freq(mpp.begin(), mpp.end());

        sort(freq.begin(), freq.end(), [](const auto& a, const auto& b){
            if(a.second == b.second){
                return a.first < b.first;           //? sort alphabetically if frequencies are equal
            }
            return a.second > b.second;             //? otherwise sort by frequency (high to low)
        });
        for(int i=0; i<k; i++){
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};