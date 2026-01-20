// ! Brute Force Approach using Validate BST for each subtree
class Solution {
private:
    bool validate(TreeNode* root, long long mini, long long maxi){
        if(root == NULL) return true;
        if(root->val >= maxi || root->val <= mini) return false;
        return validate(root->left, mini, root->val) && validate(root->right, root->val, maxi);
    }
    int count (TreeNode* root) {
        if (!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
public:
    int largestBST(TreeNode *root) {
        if (!root) return 0;
        if (validate(root, LLONG_MIN, LLONG_MAX)) {
            return count(root);
        }
        int left = largestBST(root->left);
        int right = largestBST(root->right);
        return max(left, right);
    }
};
//* Time Complexity: O(N^2) in the worst case where N is the number of nodes in the tree
//* Space Complexity: O(H) where H is the height of the tree due to recursion stack

//! Optimized Approach
class NodeValue{
public:
    int minNode, maxNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};
class Solution {
private:
    NodeValue helper(Node* root){
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0);
        auto left = helper(root->left);
        auto right = helper(root->right);
        if(left.maxNode < root->data && root->data < right.minNode){
            // Valid BST
            return NodeValue(min(left.minNode, root->data), max(root->data, right.maxNode), 1 + left.maxSize + right.maxSize);
        }
        // Not a valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
public:
    int largestBst(Node *root) {
        return helper(root).maxSize;
    }
};
//* Time Complexity: O(N) where N is the number of nodes in the tree
//* Space Complexity: O(H) where H is the height of the tree due to recursion stack


//! NOTE: BST validity depends on ALL ancestors, not just the parent.
// If current subtree is NOT a BST:
// 1) We return (INT_MIN, INT_MAX) to "poison" this subtree so that
//    parent nodes will NEVER treat it as a valid BST.
// 2) This prevents invalid BST subtrees from being merged upward.
// 3) We still propagate the maximum BST size found in left or right subtree.
// return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
