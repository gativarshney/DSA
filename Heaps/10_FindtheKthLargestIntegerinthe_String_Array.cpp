// Input: nums = ["3","6","7","10"], k = 4
// Output: "3"

//! Using int or long long data type to store the numbers will not work (using stoll and to_string) because the numbers can be very large and can exceed the maximum limit of int or long long data type. So, we will use string data type to store the numbers and compare them based on their length and lexicographical order. 

//? Optimised Approach using Min Heap (Priority Queue)
class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto cmp = [](const auto &a, const auto &b){
            if(a.size() == b.size()) return a > b;
            return a.size() > b.size();
        };

        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);

        for(auto &num : nums){
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
// Time Complexity: O(n log k) because we are iterating through the array which takes O(n) time and for each element, we are performing a heap operation which takes O(log k) time in the worst case.
// Space Complexity: O(k) because we are using a heap of size k to store the k largest elements.