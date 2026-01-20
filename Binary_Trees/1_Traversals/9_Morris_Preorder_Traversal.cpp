//! Morris preorder Traversal of a Binary Tree
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};
//* Time Complexity: O(N) where N is the number of nodes in the tree
//* Space Complexity: O(1) excluding the output array

//? Morris traversal : To perform preorder traversal in O(1) extra space by temporarily threading the tree and restoring it afterward.

// In preorder traversal, we visit the current node before its left subtree.
// just put preorder.push_back(curr->val); when we create the temporary thread to the current node.
// but in inorder traversal, we put inorder.push_back(curr->val); when we remove the temporary thread.