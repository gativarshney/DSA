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
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &it : nums){
            trie.insert(it);
        }
        int maxi = 0;
        for(auto &it : nums){
            maxi = max(maxi, trie.getMaxXOR(it));
        }
        return maxi;
    }
};
// Time Complexity: O(n * 32) for inserting n numbers into the trie and O(n * 32) for finding the maximum XOR for each number. Overall O(n).
// Space Complexity: O(n * 32) for the trie where n is the number of numbers in the input array. O(1) for the maximum XOR variable. Overall O(n).