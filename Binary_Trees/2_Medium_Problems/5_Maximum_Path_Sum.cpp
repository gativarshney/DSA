//? Problem: Maximum Path Sum in a Binary Tree
class Solution {
private:
    int pathSum(TreeNode* node, int& sum){
        if(node == NULL) return 0;
        int leftSum = max(0, pathSum(node->left, sum));
        int rightSum = max(0, pathSum(node->right, sum));
        
        sum = max(sum, node->val + leftSum + rightSum);
        return node->val + max(leftSum, rightSum);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        pathSum(root, maxSum);
        return maxSum;
    }
};
// TC: O(N)
// SC: O(H) in average case for balanced tree and O(N) in worst case for skewed tree and O(log N) for balanced tree due to recursion stack.

//* Note: We consider only positive contributions from child nodes to maximize the path sum. Thats why we use max(0, ...) while calculating leftSum and rightSum.

