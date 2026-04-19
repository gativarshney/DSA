//! Min Heapify Algorithm
class Solution {
    void heapifyDown(vector<int> &nums, int idx){
        int n = nums.size();
        int leftChildIdx = 2 * idx + 1;
        int rightChildIdx = 2 * idx + 2;
        int smallest = idx;
        if(leftChildIdx < n && nums[leftChildIdx] < nums[smallest]){
            smallest = leftChildIdx;
        }
        if(rightChildIdx < n && nums[rightChildIdx] < nums[smallest]){
            smallest = rightChildIdx;
        }
        if(smallest != idx){
            swap(nums[idx], nums[smallest]);
            heapifyDown(nums, smallest);
        }
    }
    void heapifyUp(vector<int> &nums, int idx){
        int n = nums.size();
        int parentIdx = (idx - 1) / 2;
        if(idx > 0){
            if(nums[parentIdx] > nums[idx]){
                swap(nums[parentIdx], nums[idx]);
                heapifyUp(nums, parentIdx);
            }
        }
    }
public:
    void heapify(vector<int> &nums, int ind, int val) {
        int n = nums.size();
        if(nums[ind] < val){
            nums[ind] = val;
            heapifyDown(nums, ind);
        }
        else{
            nums[ind] = val;
            heapifyUp(nums, ind);
        }
    }   
};

//! Max Heapify Algorithm
class Solution {
    void heapifyDown(vector<int> &nums, int idx){
        int n = nums.size();
        int leftChildIdx = 2 * idx + 1;
        int rightChildIdx = 2 * idx + 2;
        int largest = idx;
        if(leftChildIdx < n && nums[leftChildIdx] > nums[largest]){
            largest = leftChildIdx;
        }
        if(rightChildIdx < n && nums[rightChildIdx] > nums[largest]){
            largest = rightChildIdx;
        }
        if(largest != idx){
            swap(nums[idx], nums[largest]);
            heapifyDown(nums, largest);
        }
    }
    void heapifyUp(vector<int> &nums, int idx){
        int n = nums.size();
        int parentIdx = (idx - 1) / 2;
        if(idx > 0){
            if(nums[parentIdx] < nums[idx]){
                swap(nums[parentIdx], nums[idx]);
                heapifyUp(nums, parentIdx);
            }
        }
    }
public:
    void heapify(vector<int> &nums, int ind, int val) {
        if(nums[ind] < val){
            nums[ind] = val;
            heapifyDown(nums, ind);
        }
        else{
            nums[ind] = val;
            heapifyUp(nums, ind);
        }
    }   
};