class Solution {
    void path(TreeNode* node, string str, vector<string> &ans){
        if(node == NULL) return;

        str += to_string(node->val);

        if(node->left == NULL && node->right == NULL){
            ans.push_back(str);
            return;
        }
        else{
            str += "->";
        }

        path(node->left, str, ans);
        path(node->right, str, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        if(root == NULL) return ans;

        string str = "";
        path(root, str, ans);

        return ans;
    }
};