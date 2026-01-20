//! Lowest Common Ancestor in a Binary Search Tree
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        int currValue = root->val;
        if(currValue < p->val && currValue < q->val){
            return lowestCommonAncestor(root->right, p, q);
        }
        if(currValue > p->val && currValue > q->val){
            return lowestCommonAncestor(root->left, p, q);
        }
        return root;
    }
};
// Time Complexity: O(H) where H is the height of the tree
// Space Complexity: O(H) for the recursion stack