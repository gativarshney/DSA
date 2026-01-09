class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(root == nullptr) return true;
        if(root->left == nullptr && root->right == nullptr) return true;
        int left = 0, right = 0;
        if(root->left){
            left = root->left->data;
        }
        if(root->right){
            right = root->right->data;
        }
        if(left + right != root->data) return false;
        
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};
// Time Complexity: O(N)
// Space Complexity: O(H)