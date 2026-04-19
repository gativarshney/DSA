#include <bits/stdc++.h>
using namespace std;

class Solution {
    void heapDown(vector<int> &nums, int idx){
        int n = nums.size();
        int smallestIdx = idx;
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        if(leftChild < n && nums[leftChild] < nums[smallestIdx]){
            smallestIdx = leftChild;
        }
        if(rightChild < n && nums[rightChild] < nums[smallestIdx]){
            smallestIdx = rightChild;
        }
        if(idx != smallestIdx){
            swap(nums[idx], nums[smallestIdx]);
            heapDown(nums, smallestIdx);
        }
    }
public:
    void buildMinHeap(vector<int> &nums) {
        int n = nums.size();
        for(int i = n/2; i>=0; i--){
            heapDown(nums, i);
        }
    }
};

int main() {
    vector<int> nums = {6, 5, 2, 7, 1, 7};

    cout << "Input array: ";
    for(int it : nums) cout << it << " ";

    Solution sol;

    sol.buildMinHeap(nums);

    cout << "\nMin-heap array: ";
    for(int it : nums) cout << it << " ";

    return 0;
}

// Time Complexity: O(n) because we are calling heapifyDown for n/2 nodes and each call takes O(log n) time in the worst case, but the overall time complexity of building a heap is O(n) due to the properties of the heap structure. As not all nodes will require log n time to heapify, the average time taken is less than O(n log n).
// Space Complexity: O(1)