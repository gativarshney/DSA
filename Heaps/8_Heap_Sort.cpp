class Solution {
    void heapify(vector<int> &nums, int last, int idx){
        int largest = idx;
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        if(leftChild <= last && nums[leftChild] > nums[largest]){
            largest = leftChild;
        }
        if(rightChild <= last && nums[rightChild] > nums[largest]){
            largest = rightChild;
        }
        if(largest != idx){
            swap(nums[largest], nums[idx]);
            heapify(nums, last, largest);
        }
    }
public:
    void heapSort(vector<int>&nums) {
        int n = nums.size();
        for(int i = (n/2 - 1); i >= 0; i--){
            heapify(nums, n-1, i);
        }
        int last = n-1;
        while(last > 0){
            swap(nums[0], nums[last]);
            last--;
            if(last > 0){
                heapify(nums, last, 0);
            }
        }
    }
};
// Time Complexity: O(n log n) because we are building a max heap which takes O(n) time and then we are performing n-1 heapify operations which take O(log n) time each. { O(n) + O((n-1) log n) } => O(n log n)
// Space Complexity: O(1) because we are sorting the array in place and not using any extra space.