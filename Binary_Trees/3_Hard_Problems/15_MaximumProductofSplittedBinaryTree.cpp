//? Maximum Product of Splitted Binary Tree
class Solution {
private:
    long long totalSum = 0;
    long long maxProductValue = 0;
    long long MOD = 1e9 + 7;

    long long dfs(TreeNode* node){
        if(!node) return 0;
        long long left = dfs(node->left);
        long long right = dfs(node->right);

        long long subTreeSum = node->val + left + right;
        maxProductValue = max(maxProductValue, (subTreeSum * (totalSum - subTreeSum * 1LL)));

        return subTreeSum;
    }
    void getTotalSum(TreeNode* root){
        if(!root) return;
        totalSum += root->val;
        getTotalSum(root->left);
        getTotalSum(root->right);
    }
public:
    int maxProduct(TreeNode* root) {
        getTotalSum(root);
        dfs(root);
        return maxProductValue % MOD;
    }
};
// * TC: O(N)
// * SC: O(H)
// Using DFS twice:
// 1. First DFS to calculate the total sum of all nodes in the tree.
// 2. Second DFS to calculate the maximum product of splitted binary tree.