//? Root to Node Path in Binary Tree

class Solution{
private:
    bool getPath(TreeNode* node, vector<int>&arr, int k){
        if(node == NULL) return false;
        arr.push_back(node->val);

        if(node->val == k) {
            return true;
        }

        if(getPath(node->left, arr, k) || getPath(node->right, arr, k)) return true;

        arr.pop_back();
        return false;
    }

public:
    vector<int> solve(TreeNode* root, int value){
        vector<int> arr;
        if(root == NULL) return arr;
        getPath(root, arr, value);
        return arr;
    }
};
// Time Complexity: O(N) where N is the number of nodes in the binary tree.
// Space Complexity: O(H) where H is the height of the binary tree due to the recursion stack and the path storage.