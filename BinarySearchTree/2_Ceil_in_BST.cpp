//! Ceiling of a value refers to the value of the smallest node in the Binary Search Tree that is greater than or equal to the given key. If the ceiling node does not exist, return -1.

class Solution {
  public:
    int findCeil(Node* root, int x) {
        int ceil = -1;
        while(root){
            int value = root->data;
            if(value == x){
                ceil = value;
                return ceil;
            }
            else if(value > x){
                ceil = value;
                root = root->left;
            }
            else root = root->right;
        }
        return ceil;
    }
};
// Time Complexity : O(log N) on average for balanced BST, O(N) in worst case for skewed BST
// Space Complexity : O(1) iterative approach uses constant space.