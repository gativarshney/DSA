//? Brute Force Solution using Inorder Traversal and Sorting
class Solution {
private:
    void inorder(TreeNode* root, vector<int> &arr){
        if(root == NULL) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    void fix(TreeNode* root, vector<int> &arr, int &i){
        if(root == NULL) return;
        fix(root->left, arr, i);
        root->val = arr[i++];
        fix(root->right, arr, i);
    }
public:
    void recoverTree(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        sort(arr.begin(), arr.end());
        int i = 0;
        fix(root, arr, i);
    }
};
//* Time Complexity: O(N log N) where N is the number of nodes in the BST due to sorting.
//* Space Complexity: O(N) for the array used to store the inorder traversal of the BST

//! Optimized Solution using Inorder Traversal to find the two swapped nodes
class Solution {
private:
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);
        if(prev != NULL && (prev->val > root->val)){
            if(first == NULL){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        first = last = middle = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};
// * Time Complexity: O(N) where N is the number of nodes in the BST.
//* Space Complexity: O(H) where H is the height of the BST due to recursion stack

//! Optimized Solution using Morris Inorder Traversal to find the two swapped nodes
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = NULL;
        TreeNode* middle = NULL;
        TreeNode* last = NULL;
        TreeNode* prev = NULL;

        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                if (prev && prev->val > curr->val) {
                    if (!first) {
                        first = prev;
                        middle = curr;
                    } else {
                        last = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            }
            else {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                }
                else {
                    pred->right = NULL;
                    if (prev && prev->val > curr->val) {
                        if (!first) {
                            first = prev;
                            middle = curr;
                        } else {
                            last = curr;
                        }
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};
