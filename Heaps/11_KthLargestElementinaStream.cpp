class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0; i<nums.size(); i++){
            if(pq.size() >= k){
                int top = pq.top();
                if(top < nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
            else{
                pq.push(nums[i]);
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        
        if(pq.size() > k){
            pq.pop();
        }
        return pq.size() == k ? pq.top() : -1;
    }
};

// Time Complexity: O(n log k) for the constructor because we are iterating through the array which takes O(n) time and for each element, we are performing a heap operation which takes O(log k) time in the worst case. The add function has a time complexity of O(log k) because we are performing a heap operation which takes O(log k) time in the worst case.
// Space Complexity: O(k) because we are using a heap of size k to store the k largest elements.

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */