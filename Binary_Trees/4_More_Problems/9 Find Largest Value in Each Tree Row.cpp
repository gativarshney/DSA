class Solution {
    void solve(TreeNode* root, vector<int> &ans){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int maxi = INT_MIN;

            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                maxi = max(maxi, node->val);

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans.push_back(maxi);
        }
    }
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        solve(root, ans);

        return ans;
    }
};
// Time Complexity: O(N) as we are traversing all nodes of the tree once.
// Space Complexity: O(W) where W is the maximum width of the tree.
