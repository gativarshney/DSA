//* Construct Binary Tree from Preorder and Inorder Traversal
class Solution {
private:
    TreeNode* build(vector<int> & preorder, int preStart, int preEnd, vector<int> & inorder, int inStart, int inEnd, unordered_map<int, int> &mpp){
        if(preStart > preEnd || inStart > inEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);

        int inRoot = mpp[preorder[preStart]];
        int numsLeft = inRoot - inStart;

        root->left = build(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot-1, mpp);
        root->right = build(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, mpp);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        for(int i=0; i<inorder.size(); i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);
        return root;
    }
};
// Time Complexity : O(n), where n is the number of nodes in the tree. 
// Space Complexity : O(n), for the hashmap and recursion stack.