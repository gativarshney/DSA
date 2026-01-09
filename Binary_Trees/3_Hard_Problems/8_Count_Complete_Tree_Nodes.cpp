//* Count Complete Tree Nodes
//Every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h
//? Algorithm that runs in less than O(n) time complexity.

class Solution {
private:
    int findLeftHeight(TreeNode* node){
        int height = 0;
        while(node != NULL){
            height++;
            node = node->left;
        }
        return height;
    }
    int findRightHeight(TreeNode* node){
        int height = 0;
        while(node != NULL){
            height++;
            node = node->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);

        if(lh == rh) return (1 << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// Time Complexity Analysis:
// At each recursive call, we compute the left and right heights of the subtree.
// - Each height computation takes O(log n) time since the height of a complete binary tree is at most log n.
// - In the worst case, we make O(log n) recursive calls (tree height).
//* Therefore, total time complexity = O(log n) * O(log n) = O(log^2 n).
//* Space Complexity: O(log n) due to recursion stack (maximum depth = tree height).