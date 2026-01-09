//? Right Side View of Binary Tree

//! Iterative Approach using Level Order Traversal (BFS)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                temp[i] = node->val;
            }
            ans.push_back(temp[n-1]);
        }
        return ans;
    }
};
// Time Complexity: O(N) 
// Space Complexity: O(N) 

//! Recursive Approach using DFS
class Solution {
private:
    void recursive(TreeNode* root, int level, vector<int>& ans){
        if(root == NULL) return;
        if(level == ans.size()) ans.push_back(root->val);
        recursive(root->right, level+1, ans);
        recursive(root->left, level+1, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        recursive(root, 0, ans);
        return ans;
    }
};
//* If level == ans.size(), it means this level hasn’t been recorded yet → push the current node.
//* Here, in this approach, the size of my result vector act as a “level counter”
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree (due to recursion stack)

//! Note: Both approaches yield the same result, but the recursive DFS approach is often more elegant and concise for this problem and have better space complexity in balanced trees.