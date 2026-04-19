//! Brute Force
//? Sort in descending order using sort(nums.rbegin(), nums.rend()) and return the k-th element
//* Time Complexity: O(n log n) because we are sorting the array which takes O(n log n) time.
//* Space Complexity: O(log n)

//! Heap Sort - Better Approach using Max Heap (Heapify Algorithm)
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
    int kthLargestElement(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = (n/2 - 1); i >= 0; i--){
            heapify(nums, n-1, i);
        }
        int last = n-1;
        for(int i=0; i<k; i++){
            swap(nums[0], nums[last]);
            last--;
            heapify(nums, last, 0);
        }
        return nums[n-k];
    }
};
//* Time Complexity: O(n + k log n) because we are building a max heap which takes O(n) time and then we are performing k heapify operations which take O(log n) time each. { O(n) + O(k log n) } => O(n + k log n)
//* Space Complexity: O(log n) due to recursive stack space used by heapify function in the worst case when the heap is skewed. In the average case, the space complexity is O(1) because the height of the heap is log n and we are not using any extra space other than the input array.

//! Optimal Solution
class Solution {
public:
    int kthLargestElement(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0; i<k; i++){
            minHeap.push(nums[i]);
        }
        for(int i=k; i<n; i++){
            int x = minHeap.top();
            if(x < nums[i]){
                minHeap.pop();
                minHeap.push(nums[i]);
            }
        }
        return minHeap.top();
    }
};
//* Time Complexity: O(n log k) because we are iterating through the array which takes O(n) time and for each element, we are performing a heap operation which takes O(log k) time in the worst case.
//* Space Complexity: O(k) because we are using a heap of size k to store the k largest elements.