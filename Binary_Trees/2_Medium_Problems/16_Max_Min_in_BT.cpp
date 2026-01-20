class Solution {
    private:
    void traverse(Node* root, int &maxi, int &mini){
        if(root == NULL) return;
        maxi = max(maxi, root->data);
        mini = min(mini, root->data);
        if(root->left) traverse(root->left, maxi, mini);
        if(root->right) traverse(root->right, maxi, mini);
    }
  public:
    int findMax(Node *root) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        traverse(root, maxi, mini);
        return maxi;
    }
    int findMin(Node *root) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        traverse(root, maxi, mini);
        return mini;
    }
};
// Time Complexity: O(N), where N is the number of nodes in the binary tree.
// Space Complexity: O(H), where H is the height of the binary tree due to recursive stack space.

//! Optimized Approach:
class Solution {
  public:
    int findMax(Node *root) {
        if(root == NULL) return INT_MIN;
        return max(root->data, max(findMax(root->left), findMax(root->right)));
    }

    int findMin(Node *root) {
        if(root == NULL) return INT_MAX;
        return min(root->data, min(findMin(root->left), findMin(root->right)));
    }
};
// Time Complexity: O(N), where N is the number of nodes in the binary tree.
// Space Complexity: O(H), where H is the height of the binary tree due to recursive stack space.