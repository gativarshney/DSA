//! recursive approach
class Solution {
private:
    void traverse(TreeNode* node, vector<int> &ans){
        if(node == nullptr) return;
        traverse(node->left, ans);
        traverse(node->right, ans);
        ans.push_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(H) where H is the height of the tree due to recursion stack  

//! iterative approach using two stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* node = s1.top();
            s1.pop();
            s2.push(node);
            if(node->left != NULL) s1.push(node->left);
            if(node->right != NULL) s1.push(node->right);
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(2*N) due to the two stacks used

//! iterative approach using one stack

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            ans.push_back(node->val);
            if(node->left != NULL) st.push(node->left);
            if(node->right != NULL) st.push(node->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// Time Complexity: O(N), Space Complexity: O(H) where H is the height of the tree due to stack space

//! 2nd version of iterative approach using one stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        if(root == NULL) return postOrder;
        stack<TreeNode*> st;
        TreeNode* temp;
        TreeNode* curr = root;
        while(curr != NULL || !st.empty()){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                temp = st.top()->right;
                if(temp == NULL){   
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                        temp = st.top();
                        st.pop();
                        postOrder.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        return postOrder;
    }
};
// Time Complexity: O(2*N)
// Space Complexity: O(H) where H is the height of the tree due to stack space  
// max space complexity can go up to O(N) in case of skewed tree