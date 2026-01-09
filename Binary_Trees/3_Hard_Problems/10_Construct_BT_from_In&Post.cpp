class Solution {
public: 
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int, int> &mpp){
        if(inStart > inEnd || postStart > postEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mpp[postorder[postEnd]];

        int numsLeft = inRoot - inStart;

        root->left = build(inorder, inStart, inRoot - 1, postorder, postStart, postStart + numsLeft - 1, mpp);
        root->right = build(inorder, inRoot + 1, inEnd, postorder, postStart + numsLeft, postEnd - 1, mpp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 0) return NULL;
        if(inorder.size() != postorder.size()) return NULL;
        unordered_map<int, int> mpp;
        for(int i=0; i<n; i++){
            mpp[inorder[i]] = i;
        }
        return build(inorder, 0, n-1, postorder, 0, n-1, mpp);
    }
};

// Time Complexity: O(N), where N is the number of nodes in the binary tree. We are visiting each node exactly once to construct the tree.
// Space Complexity: O(N), the space used by the hashmap to store the indices of inorder elements and the recursion stack in the worst case.