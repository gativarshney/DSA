class Solution {
public:
    bool isHeap(vector<int>& nums) {
        int n = nums.size();
        for(int i = (n/2 - 1); i >= 0; i--){
            int leftChild = i * 2 + 1;
            int rightChild = i * 2 + 2;
            if(leftChild < n && nums[i] > nums[leftChild]) return false;
            if(rightChild < n && nums[i] > nums[rightChild]) return false;
        }
        return true;
    }
};
// Time Complexity: O(n) because we are checking each node and its children once.
// Space Complexity: O(1) because we are using only constant extra space.