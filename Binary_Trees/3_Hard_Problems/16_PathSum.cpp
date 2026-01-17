class Solution {
private:
    bool isLeaf(TreeNode* node){
        if(node != NULL && node->left == NULL && node->right ==  NULL) return true;
        return false;
    }
    void pathSum(TreeNode* node, int targetSum, int sum, bool &match){
        if(match) return;
        if(node != NULL) sum += node->val;
        if(isLeaf(node)){
            if(sum == targetSum){
                match = 1;
                return;
            }
        }
        if(node->left) pathSum(node->left, targetSum, sum, match);
        if(node->right) pathSum(node->right, targetSum, sum, match);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        bool match = false;
        pathSum(root, targetSum, 0, match);
        return match;
    }
};
// Time Complexity: O(N) where N is the number of nodes in the binary tree.
// Space Complexity: O(H) where H is the height of the binary tree due to recursive call stack.


//! ***************************************
//! Minimal Clean Approach
// At each node:
// Subtract node value from target
// If leaf → check if target becomes 0
// Otherwise recurse

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        if (!root->left && !root->right)
            return targetSum == root->val;

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
// Time Complexity: O(N) where N is the number of nodes in the binary tree.
// Space Complexity: O(H) where H is the height of the binary tree due to recursive call stack.