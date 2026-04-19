class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(int i : nums) mpp[i]++;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto it : mpp){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
// Time Complexity: O(N log K) where N is the number of elements in the input array and K is the number of top frequent elements to return. This is because we are iterating through the map of frequencies and maintaining a min-heap of size K.
// Space Complexity: O(N) for the map that stores the frequency of each element and O(K) for the min-heap that stores the top K elements. Overall, the space complexity is O(N + K), which simplifies to O(N) in the worst case when K is much smaller than N.