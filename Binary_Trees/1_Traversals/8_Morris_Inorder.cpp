//! Morris Inorder Traversal of a Binary Tree
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr != NULL){
            // Case 1: If there is no left child
            if(curr->left == NULL){
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            // Case 2: If there is a left child
            else{
                // Finding the rightmost node in the left subtree or the temporary thread to the current node
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                // Creating a temporary thread to the current node
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                // Removing the temporary thread and visiting the current node
                else{
                    prev->right = NULL;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return inorder;
    }
};
//* Time Complexity: O(N) where N is the number of nodes in the tree
//* Space Complexity: O(1) excluding the output array

//! NOTE: In morris traversal, we just have to go to the rightmost node of left subtree, then it will create a temporary thread to the current node.

//? Morris traversal : To perform inorder traversal in O(1) extra space by temporarily threading the tree and restoring it afterward.