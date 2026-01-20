//! Two Sum IV - Input is a BST

//* Brute Force Approach using Inorder Traversal and Two Pointers
class Solution {
private:    
    void inorder(TreeNode* root, vector<int> &arr){
        if(root == NULL) return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }   
public:
    bool findTarget(TreeNode* root, int k) {    
        vector<int> arr;
        inorder(root, arr);
        int left = 0, right = arr.size() - 1;
        while(left < right){
            int sum = arr[left] + arr[right];
            if(sum == k) return true;
            else if(sum < k) left++;
            else right--;
        }
        return false;
    }
};
// Time Complexity: O(2*N) where N is the number of nodes in the BST.
// Space Complexity: O(N) for the array used to store the inorder traversal of the BST.

//* Brute Force Approach using Hashing (also works for a general binary tree)
class Solution {
private:
    bool dfs(TreeNode* root, unordered_set<int> &st, int k){
        if(root == NULL) return false;
        if(st.count(k - root->val)) return true;
        st.insert(root->val);
        return dfs(root->left, st, k) || dfs(root->right, st, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return dfs(root, st, k);
    }
};
// Time Complexity: O(N) where N is the number of nodes in the BST.
// Space Complexity: O(N) for the unordered_set used to store the node values.

//! Optimized Approach using BST Iterator and Two Pointers
class BSTIterator{
public:
    stack<TreeNode*> st;
    bool reverse = true;
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
private:
    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            if(!reverse) node = node->left;
            else node = node->right;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i < j){
            int sum = i + j;
            if(sum == k) return true;
            else if(sum < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};
// Time Complexity: O(N) in the worst case where N is the number of nodes in the BST.
// Space Complexity: O(h) where h is the height of the tree for the two stacks used in the BST iterators.
// This approach efficiently uses the properties of the BST to find the target sum without storing all node values.
// It uses two iterators to traverse the tree from the smallest and largest values simultaneously.