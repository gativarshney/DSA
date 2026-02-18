class Solution {
private:
    int solve(vector<int> &nums){
        int prev2 = 0;
        int prev = nums[0];
        for(int i=1; i<nums.size(); i++){
            int pick = nums[i];
            if(i > 1) pick += prev2;
            int notPick = 0 + prev;
            int curi = max(pick, notPick);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0; i<nums.size(); i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != nums.size()-1) temp2.push_back(nums[i]);
        }
        return max(solve(temp1), solve(temp2));
    }
};

//* Time Complexity: O(n)
//* Space Complexity: O(n), O(1) for DP logic Extra O(n) due to temp arrays

/*
HOUSE ROBBER II (Circular Houses)

Problem:
Houses are arranged in a circle → first and last are adjacent.
Cannot rob adjacent houses.

Key Insight:
We cannot take both first and last house.
So break the problem into two linear cases:

1) Exclude first house → rob houses [1 … n-1]
2) Exclude last house  → rob houses [0 … n-2]

Answer = max(case1, case2)

Edge Case: If only one house → return nums[0]
*/
