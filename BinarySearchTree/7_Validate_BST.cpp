//! NOTE: BST validity depends on ALL ancestors, not just the parent.

class Solution {
private:
    bool validate(TreeNode* root, long long mini, long long maxi){
        if(root == NULL) return true;
        if(root->val >= maxi || root->val <= mini) return false;
        return validate(root->left, mini, root->val) && validate(root->right, root->val, maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

// Time Complexity: O(N) where N is the number of nodes in the tree
// Space Complexity: O(H) where H is the height of the tree due to recursion stack