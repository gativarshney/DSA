class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> pairXor;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){

                int val = nums[i] ^ nums[j];
                pairXor.insert(val);

            }
        }

        unordered_set<int> ans;

        for(auto &it : pairXor){
            for(int i = 0; i < n; i++){
                ans.insert(it ^ nums[i]);
            }
        }

        return ans.size();
    }
};
