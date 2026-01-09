//! Recursive Approach
class Solution {
private:
    void traverse(TreeNode* node, vector<int>& ans){
        if(node == nullptr) return;
        ans.push_back(node->val);
        traverse(node->left, ans);
        traverse(node->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree due to recursion stack 
// max space complexity can go up to O(N) in case of skewed tree
// Auxiliary Space: O(N) for the output vector
// where N is the number of nodes in the tree

//! Iterative Approach
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preOrder;
        if(root == NULL) return preOrder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preOrder.push_back(root->val);
            if(root->right != nullptr) st.push(root->right);
            if(root->left != nullptr) st.push(root->left);
        }
        return preOrder;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree due to stack space

