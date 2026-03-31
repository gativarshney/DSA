class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);
        int maxi = 1, lastIndex = 0;
        for(int i=0; i<n; i++) hash[i] = i;
        for(int idx=0; idx<n; idx++){
            for(int prev=0; prev<idx; prev++){
                if(nums[idx] % nums[prev] == 0 && dp[idx] < 1 + dp[prev]){
                    dp[idx] = 1 + dp[prev];
                    hash[idx] = prev;
                }
                if(maxi < dp[idx]){
                    maxi = dp[idx];
                    lastIndex = idx;
                }
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while(lastIndex != hash[lastIndex]){
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
};
// Time Complexity: O(n^2) for the nested loops, O(n log n) for sorting, overall O(n^2)
// Space Complexity: O(n) for dp and hash arrays, O(n) for the largest divisible subset array.
//* Similar to longest increasing subsequence, we sort the array and then use dynamic programming to find the largest divisible subset. We also use a hash array to store the previous index and backtrack to find the actual subset.