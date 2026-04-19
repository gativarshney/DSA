class Solution {
    void heapifyDown(vector<int> &nums, int idx){
        int n = nums.size();
        int largest = idx;
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        if(leftChild < n && nums[leftChild] > nums[largest]){
            largest = leftChild;
        }
        if(rightChild < n && nums[rightChild] > nums[largest]){
            largest = rightChild;
        }
        if(idx != largest){
            swap(nums[idx], nums[largest]);
            heapifyDown(nums, largest);
        }
    }
public:
    vector<int> minToMaxHeap(vector<int> nums) {
        int n = nums.size();
        for(int i = (n/2 - 1); i >= 0; i--){
            heapifyDown(nums, i);
        }
        return nums;
    }
};
// Time Complexity: O(n) because we are calling heapifyDown for n/2 nodes and each call takes O(log n) time in the worst case, but the overall time complexity of building a heap is O(n) due to the properties of the heap structure. As not all nodes will require log n time to heapify, the average time taken is less than O(n log n).
// Space Complexity: O(1) because we are modifying the input array in place and not using any extra space.