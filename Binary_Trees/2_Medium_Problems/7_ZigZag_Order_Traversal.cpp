//? ZigZag Level Order Traversal of a Binary Tree
//? Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
//? (i.e., from left to right, then right to left for the next level and alternate between).

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> arr;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                arr.push_back(node->val);
            }
            ans.push_back(arr);
        }
        for(int i=1; i<ans.size(); i+=2){
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
// TC: O(N) where N is number of nodes in the tree
// SC: O(N) for the queue and the answer array

//* Alternate Approach without using reverse function (Flag method)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> arr(n);
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                int index = leftToRight ? i : (n - 1 - i);
                arr[index] = node->val;
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
            leftToRight = !leftToRight;
            ans.push_back(arr);
        }
        return ans;
    }
};