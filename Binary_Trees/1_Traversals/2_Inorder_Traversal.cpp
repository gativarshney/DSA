class Solution {
private: 
    void traverse(TreeNode* node, vector<int> &ans){
        if(node == nullptr) return;
        traverse(node->left, ans);
        ans.push_back(node->val);
        traverse(node->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree due to recursion stack  
// max space complexity can go up to O(N) in case of skewed tree
// Auxiliary Space: O(N) for the output vector  
// where N is the number of nodes in the tree

//! Iterative Approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        if(root == NULL) return inOrder;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()) break;
                node = st.top();
                st.pop();
                inOrder.push_back(node->val);
                node = node->right;
            }
        }
        return inOrder;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree due to stack space  
// max space complexity can go up to O(N) in case of skewed tree
