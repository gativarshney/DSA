class Solution {
    int solve(TreeNode* root){
        if(!root) return -1;

        queue<TreeNode*> q;
        q.push(root);

        int ans = -1;

        while(!q.empty()){
            int size = q.size();

            ans = q.front()->val;
            
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return ans;
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        return solve(root);
    }
};
// Time Complexity: O(N) as we are traversing all nodes of the tree once.
// Space Complexity: O(W) where W is the maximum width of the tree. In the worst case, the maximum width can be O(N/2) for a complete binary tree, which simplifies to O(N). In a skewed tree, the width would be O(1).