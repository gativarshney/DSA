//* Construct BST from PreOrder Traversal

//? Brute Force Approach:
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1; i < preorder.size(); i++) {
            TreeNode* curr = root;
            TreeNode* newNode = new TreeNode(preorder[i]);
            while(true) {
                if(preorder[i] < curr->val) {
                    if(curr->left == nullptr) {
                        curr->left = newNode;
                        break;
                    } else {
                        curr = curr->left;
                    }
                } else {
                    if(curr->right == nullptr) {
                        curr->right = newNode;
                        break;
                    } else {
                        curr = curr->right;
                    }
                }
            }
        }
        return root;
    }
};
// Time Complexity: O(N^2) in worst case (skewed tree), O(N log N) on average
// Space Complexity: O(1) excluding recursion stack

//? Using Inorder Traversal:
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int& preIndex, unordered_map<int, int>& mpp) {
        if(inStart > inEnd) return nullptr;
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int inIndex = mpp[rootVal];
        root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex, mpp);
        root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex, mpp);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        unordered_map<int, int> mpp;
        for(int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        int preIndex = 0;
        return buildTree(preorder, inorder, 0, inorder.size() - 1, preIndex, mpp);
    }
};
// Time Complexity: O(N log N) due to sorting
// Space Complexity: O(N) for the hashmap and recursion stack 

//! Optimal Approach:
class Solution {
private:
    TreeNode* build(vector<int> & preorder, int &i, int bound){
        if(i == preorder.size() || preorder[i] > bound) return NULL;
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};
// Time Complexity : O(n), where n is the number of nodes in the tree. 
// Space Complexity : O(h), for the recursion stack where h is the height of the tree.

//* Every recursive call returns the root of the subtree it just built.
//* The very first call builds the whole tree, so it finally returns 8.