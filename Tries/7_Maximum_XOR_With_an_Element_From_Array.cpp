//! Leetcode - HARD

//! Brute Force
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> ans;
        for(auto &it : queries){
            int maxXOR = -1;
            for(int i=0; i<n; i++){
                if(nums[i] <= it[1]){
                    maxXOR = max(maxXOR, (nums[i] ^ it[0]));
                }
            }
            ans.push_back(maxXOR);
        }
        return ans;
    }
};
// Time Complexity: O(m * n) where m is the number of queries and n is the number of numbers in the input array. For each query, we iterate through all numbers in the input array to find the maximum XOR. Overall O(m * n).
// Space Complexity: O(m) for the answer vector where m is the number of queries.

//! Optimal Code using Trie

struct Node{
    Node* links[2] = {nullptr};
    bool containsKey(int bit){
        return (links[bit] != nullptr);
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMaxXOR(int num){
        Node* node = root;
        int maxXOR = 0;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(node->containsKey(1 - bit)){
                maxXOR = maxXOR | (1 << i);
                node = node->get(1 - bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxXOR;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> offlineQueries;
        int q = queries.size();

        for(int i = 0; i < q; i++){
            int xi = queries[i][0];
            int mi = queries[i][1];
            offlineQueries.push_back({mi, {xi, i}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());
        vector<int> ans(q, -1);

        int idx = 0;
        int n = nums.size();
        Trie trie;
        for(int i = 0; i < q; i++){
            int mi = offlineQueries[i].first;
            int xi = offlineQueries[i].second.first;
            int qIdx = offlineQueries[i].second.second;

            while(idx < n && nums[idx] <= mi){
                trie.insert(nums[idx]);
                idx++;
            }
            if(idx == 0) ans[qIdx] = -1;
            else ans[qIdx] = trie.getMaxXOR(xi);
        }
        return ans;
    }
};

// Time Complexity: O(n log n + q log q + n + q)
// Space Complexity: O(n * 36 + q * 36) = O(n + q)