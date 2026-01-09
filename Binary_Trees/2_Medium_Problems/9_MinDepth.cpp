class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = minDepth(root->left);
        int rh = minDepth(root->right);

        if (root->left == nullptr) return 1 + rh;
        if (root->right == nullptr) return 1 + lh;
        return 1 + min(lh, rh);
    }
};
// TC: O(N) 
// SC: O(H) where H is the height of the tree (due to recursion stack)
// In worst case (skewed tree) O(N))
// In best case (balanced tree) O(log N)