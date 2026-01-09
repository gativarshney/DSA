// Brute Force, TC: O(N*N) , SC:O(1)
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int sum = 0;
        for (int j = i; j < nums.size(); ++j) {
            sum += nums[j];
            if (sum == goal) {
                cnt++;
            }
        }
    }
    return cnt;
}

// Better Approach, TC: O(N), SC: O(N)
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;
    int sum = 0, cnt = 0;
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(prefixSum.find(sum - goal) != prefixSum.end()){
            cnt += prefixSum[sum - goal];
        }
        prefixSum[sum]++;
    }
    return cnt;
}


// Optimal; TC: O(2N * 2), SC: O(1)
class Solution {
private:
    int atmost(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int n = nums.size();
        int l = 0, r = 0, sum = 0, cnt = 0;
        while(r < n){
            sum += nums[r];
            while(sum > goal){
                sum -= nums[l];
                l++;
            }
            cnt += (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums, goal) - atmost(nums, goal-1);
    }
};
// atmost(nums, goal) counts how many subarrays have sum ≤ goal.