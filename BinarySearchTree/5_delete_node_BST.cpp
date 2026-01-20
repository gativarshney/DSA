class Solution {
private:
    TreeNode* findLastRight(TreeNode* node){
        while(node->right != NULL){
            node = node->right;
        }
        return node;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return helper(root);
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->val > key){
                if(curr->left != NULL && curr->left->val == key){
                    curr->left = helper(curr->left);
                    break;
                }
                else curr = curr->left;
            }
            else{
                if(curr->right != NULL && curr->right->val == key){
                    curr->right = helper(curr->right);
                    break;
                }
                else curr = curr->right;
            }
        }
        return root;
    }
};
// Time Complexity: O(h) where h is the height of the tree.
// Space Complexity: O(1)