class Solution {
    void solve(TreeNode* node, int sum, int target, vector<int> temp, vector<vector<int>> &ans){
        if(node == NULL) return;

        temp.push_back(node->val);
        sum += node->val;

        if(!node->left && !node->right){
            if(sum == target){
                ans.push_back(temp);
                return;
            }
        }

        solve(node->left, sum, target, temp, ans);
        solve(node->right, sum, target, temp, ans);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;

        vector<int> temp;
        int sum = 0;

        solve(root, sum, targetSum, temp, ans);

        return ans;
    }
};
//* Time Complexity: O(N * H) as we are creating a new vector for each path, and in the worst case, there can be O(N) paths of length O(H) in a skewed tree.
//* Space Complexity: O(N * H) in worst case ~ O(N^2) in skewed tree, as we are storing all paths in the answer vector, and each path can have up to O(H) nodes. In a balanced tree, it would be O(N * log N).

//! Optimised Solution
class Solution {
    void solve(TreeNode* node, int sum, int target, vector<int> &temp, vector<vector<int>> &ans){
        if(node == NULL) return;

        temp.push_back(node->val);
        sum += node->val;

        if(!node->left && !node->right){
            if(sum == target){
                ans.push_back(temp);    // Tc: O(H) as we are copying the path of length H to the answer vector. So if P is the number of valid paths, this contributes O(P * H) to the time complexity.
            }
        }
        else{
            solve(node->left, sum, target, temp, ans);
            solve(node->right, sum, target, temp, ans);
        }

        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;

        vector<int> temp;
        int sum = 0;

        solve(root, sum, targetSum, temp, ans);

        return ans;
    }
};
//* Time Complexity: O(N + P * H)
//* Space Complexity: O(H) excluding output
//
// N = number of nodes
// H = height of tree
// P = number of valid root-to-leaf paths

// So, Time Complexity: O(N) excluding output-copy cost
// Time Complexity: O(N + P * H) including output-copy cost