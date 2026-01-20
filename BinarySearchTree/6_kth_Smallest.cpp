//! brute-force inorder-based approach.
class Solution {
private:
    void inorder(TreeNode* root, vector<int> &arr){
        if(root == NULL) return;
        if(root->left) inorder(root->left, arr);
        arr.push_back(root->val);
        if(root->right) inorder(root->right, arr);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr);
        return arr[k-1];
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N) for the auxiliary array  

//! optimal inorder-based approach.
class Solution {
private:
    void inorder(TreeNode* root, int &cnt, int &ans){
        if(root == NULL || cnt <= 0) return;
        if(root->left) inorder(root->left, cnt, ans);
        cnt--;
        if(cnt == 0){
            ans = root->val;
            return;
        }
        if(root->right) inorder(root->right, cnt, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};
// Time Complexity: O(H + k) where H is the height of the tree
// Time = cost to reach leftmost node + cost to visit k nodes

// Space Complexity: O(H) for the recursion stack


//! Morris Traversal-based approach.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left == NULL) {
                // Visit current node
                k--;
                if (k == 0) return curr->val;
                curr = curr->right;
            } 
            else {
                // Find inorder predecessor
                TreeNode* prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }

                // Create thread
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                // Remove thread and visit node
                else {
                    prev->right = NULL;
                    k--;
                    if (k == 0) return curr->val;
                    curr = curr->right;
                }
            }
        }
        return -1; // safety
    }
};
// Time Complexity: O(H + k) in the worst case
// Space Complexity: O(1)

//? Morris traversal = inorder traversal without stack or recursion using temporary links.