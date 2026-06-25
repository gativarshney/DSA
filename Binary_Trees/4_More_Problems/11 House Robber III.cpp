class Solution {
    int solve(TreeNode* node, unordered_map<TreeNode*, int> &dp){
        if(!node) return 0;

        if(dp.count(node)) return dp[node];

        int notTake = solve(node->left, dp) + solve(node->right, dp);

        int take = node->val;
        if(node->left){
            take += solve(node->left->left, dp) + solve(node->left->right, dp);
        }
        if(node->right){
            take += solve(node->right->left, dp) + solve(node->right->right, dp);
        }
        
        return dp[node] = max(take, notTake);
    }
public:
    int rob(TreeNode* root) {
        if(!root) return 0;

        unordered_map<TreeNode*, int> dp;

        return solve(root, dp);
    }
};
//* Time Complexity: O(N)
//* Space Complexity: O(N) + O(H) 
// O(N) due to the unordered_map storing results for each node, and O(H) for the recursion stack, where H is the height of the tree. In the worst case of a skewed tree, this can go up to O(N). In a balanced tree, it would be O(log N).