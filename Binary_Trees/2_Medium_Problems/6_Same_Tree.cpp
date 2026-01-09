//? Problem: Same Tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL) {
            return (p == q);
        }
        return (p->val == q->val) 
            && isSameTree(p->left, q->left) 
            && isSameTree(p->right, q->right);
    }
};
// TC: O(N)
// SC: O(H) in average case, O(N) in worst case for skewed tree and O(log N) for balanced tree due to recursion stack.
