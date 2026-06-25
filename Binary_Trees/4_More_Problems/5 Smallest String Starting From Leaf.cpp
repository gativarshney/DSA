class Solution {
    void solve(TreeNode* node, string str, vector<string> &ans){
        if(node == NULL) return;

        str += (node->val + 'a');

        if(!node->left && !node->right){
            reverse(str.begin(), str.end());
            ans.push_back(str);
            return;
        }

        solve(node->left, str, ans);
        solve(node->right, str, ans);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        vector<string> ans;
        string str = "";

        if(!root) return str;

        solve(root, str, ans);

        sort(ans.begin(), ans.end());
        
        return ans[0];
    }
};
//* Time Complexity: O(N * H + K * log(K) * H)
//* Space Complexity: O(K * H)
//
// N = total number of nodes in the tree
// K = total number of leaf nodes in the tree
// H = height of the tree

// N * H comes from string copying during DFS as new string is created, and K log K * H comes from sorting K strings of length up to H.

//! Optimised Solution
class Solution {
    void solve(TreeNode* node, string str, string &ans){
        if(node == NULL) return;

        str += (node->val + 'a');

        if(!node->left && !node->right){
            reverse(str.begin(), str.end());
            if(ans.empty() || str < ans) ans = str;         
            return;
        }

        solve(node->left, str, ans);
        solve(node->right, str, ans);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        string str = "";

        if(!root) return ans;

        solve(root, str, ans);

        return ans;
    }
};
//* Time Complexity: O(N * H)
//* Space Complexity: O(H)