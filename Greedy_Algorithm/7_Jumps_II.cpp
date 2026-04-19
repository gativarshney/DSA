class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int r = 0, l = 0;
        while(r < n-1){
            int farthest = 0;
            for(int i = l; i <= r; i++){
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};
// Time Complexity: O(n) where n is the size of the input array. We traverse the array once to determine the minimum number of jumps required.
// Space Complexity: O(1) as we are using only a constant amount of extra space