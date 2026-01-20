class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        TreeNode* curr = root;
        while(true){
            if(curr->val <= val){
                if(curr->right == nullptr){
                    curr->right = new TreeNode(val);
                    break;
                }
                else{
                    curr = curr->right;
                }
            }
            else{
                if(curr->left == nullptr){
                    curr->left = new TreeNode(val);
                    break;
                }
                else{
                    curr = curr->left;
                }
            }
        }
        return root;
    }
};
// Time Complexity: O(log N) {base 2}
// Space Complexity: O(1) iterative approach.