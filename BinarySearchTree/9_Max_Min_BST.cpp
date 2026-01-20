// Find Min/Max in BST

int findMax(Node* root) {
    while (root->right) root = root->right;
    return root->data;
}

int findMin(Node* root) {
    while (root->left) root = root->left;
    return root->data;
}
// Time Complexity: O(H), where H is the height of the BST.
// Space Complexity: O(1).