class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<int>> mpp;

        for(int i = 0; i < n; i++){

            string temp = strs[i];
            sort(temp.begin(), temp.end());
            mpp[temp].push_back(i);

        }

        vector<vector<string>> ans;

        for(auto &it : mpp){
            vector<int> arrIdx = it.second;

            vector<string> temp;

            for(int i = 0; i < arrIdx.size(); i++){
                temp.push_back(strs[arrIdx[i]]);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};