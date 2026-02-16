class Solution {
private:
    void inorder(TreeNode* node, vector<int> &order){
        if(node == NULL) return;
        inorder(node->left, order);
        order.push_back(node->val);
        inorder(node->right, order);
    }
    TreeNode* build(vector<int>& arr, int left, int right){
        if(left > right) return NULL;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = build(arr, left, mid - 1);
        root->right = build(arr, mid + 1, right);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> sorted;
        inorder(root, sorted);
        return build(sorted, 0, sorted.size() - 1);
    }
};

//* Time Complexity: O(n), where n is the number of nodes in the binary search tree. The inorder traversal takes O(n) time, and building the balanced BST also takes O(n) time.
//* Space Complexity: O(n), where n is the number of nodes in the binary search tree. The space used to store the sorted values in the vector takes O(n) space, and the recursive call stack for building the balanced BST also takes O(n) space in the worst case.