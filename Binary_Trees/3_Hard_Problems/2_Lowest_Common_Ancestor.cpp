//? Lowest Common Ancestor in Binary Tree

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;
    }
};
// Time Complexity: O(N) where N is the number of nodes in the binary tree.
// Space Complexity: O(H) where H is the height of the binary tree due to the recursion stack.
// SC: O(N) in the worst case for skewed tree and O(log N) for balanced tree.