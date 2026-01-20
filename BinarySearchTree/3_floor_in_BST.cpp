//! Floor of a value refers to the value of the largest node in the Binary Search Tree that is smaller than or equal to the given key. If the floor node does not exist, return nullptr.

class Solution {
  public:
    int floor(Node* root, int x) {
        int floorVal = -1;
        while(root){
            int val = root->data;
            if(val == x){
                floorVal = val;
                return floorVal;
            }
            else if(val < x){
                floorVal = val;
                root = root->right;
            }
            else root = root->left;
        }
        return floorVal;
    }
};
// Time Complexity: O(log N) {base 2}
// Space Complexity: O(1) iterative approach.