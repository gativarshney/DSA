//* Flatten Binary Tree to Linked List
//* The "linked list" should be in the same order as a pre-order traversal of the binary tree.

//!Approach-1: Reverse Preorder Traversal (Right -> Left -> Node)
class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
// Time Complexity: O(N) 
// Space Complexity: O(H)

//!Approach-2: Iterative using Stack
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            if(!st.empty()){
                curr->right = st.top();
                curr->left = NULL;
            }
        }
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N)

//!Approach-3: Morris Traversal
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left != NULL){
                TreeNode* prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
// Time Complexity: O(N)
// Space Complexity: O(1)