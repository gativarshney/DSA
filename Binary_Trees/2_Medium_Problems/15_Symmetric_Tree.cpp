class Solution {
private:
    bool symmetricHelper(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right;
        }
        if(left->val != right->val) return false;
        return symmetricHelper(left->left, right->right) && symmetricHelper(left->right, right->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return (root == NULL || symmetricHelper(root->left, root->right));
    }
};
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree due to recursive stack space. Best case O(log N) for balanced tree and worst case O(N) for skewed tree.

//! Iterative Approach using Queue
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()){
            TreeNode* left = q.front(); q.pop();
            TreeNode* right = q.front(); q.pop();
            
            if(left == NULL && right == NULL) continue;
            if(left == NULL || right == NULL) return false;
            if(left->val != right->val) return false;
            
            // Push children in mirrored order
            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }
        return true;
    }
};
//Time Complexity: O(N)
//Space Complexity: O(N) in the worst case for the queue.
