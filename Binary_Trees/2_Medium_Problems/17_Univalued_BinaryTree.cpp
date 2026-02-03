//! Approach-1
class Solution {
private:
    bool dfs(TreeNode* node, int value){
        if(node->val != value) return false;
        if(node->left && (dfs(node->left, value) == false)) return false;
        if(node->right && (dfs(node->right, value) == false)) return false;
        return true;
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        int value = root->val;
        return dfs(root, value);
    }
};

//! Approach-2
class Solution {
private:
    bool dfs(TreeNode* node, int value){
        if(node == NULL) return true;
        return (node->val == value) && dfs(node->left, value) && dfs(node->right, value);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL) return true;
        int value = root->val;
        return dfs(root, value);
    }
};