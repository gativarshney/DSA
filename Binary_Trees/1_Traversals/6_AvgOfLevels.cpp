class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n =  q.size();
            double sum = 0;
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                sum += node->val;
            }
            double avgVal = sum / n;
            ans.push_back(avgVal);
        }
        return ans;
    }
};
// TC: O(N)
// SC: O(N)