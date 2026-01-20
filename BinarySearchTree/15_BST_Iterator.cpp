//! Recursive Approach using Inorder Traversal
class BSTIterator {
public:
    vector<TreeNode*> inorder;
    int i = 0;
    void inOrder(TreeNode* root, vector<TreeNode*> &inorder){
        if(root == NULL) return;
        inOrder(root->left, inorder);
        inorder.push_back(root);
        inOrder(root->right, inorder);
    }
    BSTIterator(TreeNode* root) {
        inOrder(root, inorder);
    }
    
    int next() {
        return inorder[i++]->val;
    }
    
    bool hasNext() {
        return (i < inorder.size());
    }
};

//* Time Complexity: O(n) for initialization, O(1) for next() and hasNext()
//* Space Complexity: O(n) for storing inorder traversal

//! Opimized Approach using Stack
class BSTIterator {
private: 
    stack<TreeNode*> st;
    void pushLeft(TreeNode* node, stack<TreeNode*> &st){
        while(node){
            st.push(node);
            node = node->left;
        }
    }
public:
    BSTIterator(TreeNode* root) {
        if(root){
            pushLeft(root, st);
        }
    }
    int next() {
        TreeNode* node = st.top();
        st.pop();
        int value = node->val;
        if(node->right){
            pushLeft(node->right, st);
        }
        return value;
    }
    bool hasNext() {
        return (!st.empty());
    }
};
//* Time Complexity: O(h) for initialization, O(1) amortized for next() and O(1) for hasNext()
//* Space Complexity: O(h) for stack where h is the height of the tree

//? NOTE:
//? “Amortized O(1) means that while a single operation may take longer, the total cost of all operations divided by the number of operations is constant.”

// Push operations = N & Pop operations = N
// Total operations = 2N
// Total time = O(N)
// Now divide that over N next() calls:
// Average per call = O(1)
// next() runs in amortized O(1) time