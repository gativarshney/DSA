//? Check for Balanced Tree
//* A binary tree is balanced if for each node, the difference between heights of left and right subtrees is at most 1. (i.e., -1, 0, or 1)

class Solution {
private:
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int leftHeight = height(root->left);
        if(leftHeight == -1) return -1;
        int rightHeight = height(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        if(height(root) == -1) return false;
        return true;
    }
};
// TC: O(N)
// SC: O(H) where H is the height of the tree (due to recursion stack)
// In worst case (skewed tree) O(N))
// In best case (balanced tree) O(log N)

//! Simple Solution to understand
class Solution {
    pair<bool, int> isBalancedFast(TreeNode* root){
        if(root == NULL){
            return {true, 0};
        }


        pair<bool, int> left = isBalancedFast(root->left);
        pair<bool, int> right = isBalancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;
        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        return isBalancedFast(root).first;
    }
};
// TC: O(N)
// SC: O(H) where H is the height of the tree (due to recursion stack)