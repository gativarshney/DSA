//! Brute Force Approach
class Solution {
    void solve(TreeNode* node, long long sum, int &target, int &cnt){
        if(node == NULL) return;

        sum += node->val;

        if(sum == target){
            cnt++;
        }

        solve(node->left, sum, target, cnt);
        solve(node->right, sum, target, cnt);
    }

    void traverse(TreeNode* node, int &target, int &cnt){
        if(node == NULL) return;

        solve(node, 0, target, cnt);

        traverse(node->left, target, cnt);
        traverse(node->right, target, cnt);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;

        int cnt = 0;

        traverse(root, targetSum, cnt);

        return cnt;
    }
};
// * Time Complexity: O(N^2) in worst case (skewed tree) as we are traversing each node and for each node, we are doing a DFS which can take O(N) time. In a balanced tree, it would be O(N log N).
// * Space Complexity: O(H) where H is the height of the tree due to recursion stack, which can go up to O(N) in case of skewed tree.