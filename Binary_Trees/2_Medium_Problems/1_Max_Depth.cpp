//! A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

//* Iterative Level Order Traversal Approach
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};
// TC: O(N)
// SC: O(w) where w is the maximum width of the tree

//* Optimized Recursive Approach
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};
// TC: O(N)
// SC: O(H) where H is the height of the tree (due to recursion stack
// In worst case (skewed tree) O(N))
// In best case (balanced tree) O(log N)