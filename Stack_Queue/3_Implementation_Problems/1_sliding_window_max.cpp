//! Brute Force Approach
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1);
        for(int i=0; i<=n-k; i++){
            int maxi = INT_MIN;
            for(int j=i; j<i+k; j++){
                maxi = max(nums[j], maxi);
            }
            ans[i] = maxi;
        }
        return ans;
    }
};
// TC: O(n * k) SC: O(n - k)

//! Optimized Approach using Deque

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1 || k == 1) return nums;
        if(n == k){
            int maxi = INT_MIN;
            for(int i=0; i<n; i++){
                maxi = max(maxi, nums[i]);
            }
            return {maxi};
        }
        vector<int> ans;
        deque<int> deq;
        for(int i=0; i<n; i++){
            if(!deq.empty() && deq.front() <= i-k) deq.pop_front();
            while(!deq.empty() && nums[deq.back()] <= nums[i]){
                deq.pop_back();
            }
            deq.push_back(i);
            if(i >= k-1) ans.push_back(nums[deq.front()]);
        }
        return ans;
    }
};

// TC: O(2*N) SC: O(k) for deque and O(n-k) for ans