#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        int size = n-k+1;
        vector<int> ans(size);
        for(int i=0; i<size; i++){
            int xsum = 0;
            unordered_map<int, int> mpp;
            for(int j=i; j<k+i; j++){
                mpp[nums[j]]++;
            }
            vector<pair<int,int>> freq(mpp.begin(), mpp.end());
            sort(freq.begin(), freq.end(), [](const auto& a, const auto& b){
                if(a.second == b.second) return a.first > b.first;
                return a.second > b.second;
            });
            if(freq.size() < x){
                xsum = accumulate(nums.begin()+i, nums.begin()+i+k, 0);
            }
            else {
                for(int a=0; a<x; a++){
                    xsum += freq[a].first * freq[a].second;
                }
            }
            ans[i] = xsum;
        }
        return ans;
    }
};

// - n = size of nums
// - k = window size
// - m = number of unique elements in a window (at most k)
// - w = n-k+1 = number of windows

// TC: O(n * (k + mlogm + (k or x))) --> O(n * (k log k + max(k, x)))
//! Overall final TC: O(n * klog k)

//Per window
// - unordered_map<int, int> mpp → up to k unique elements → O(k)
// - vector<pair<int, int>> freq → same as map → O(k)
// - vector<int> ans → stores n-k+1 results → O(n)

//! SC : O(n + k) only this as it is reused everytime


