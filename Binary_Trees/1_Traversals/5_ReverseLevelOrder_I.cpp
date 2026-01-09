// Original 2D Vector Approach
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        vector<int> final;
        if(root == NULL) return final;
        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* node = q.front();
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                level.push_back(node->data);
            }
            ans.push_back(level);
        }
        for(int i=ans.size()-1; i>=0; i--){
            for(int j=0; j<ans[i].size(); j++){
                final.push_back(ans[i][j]);
            }
        }
        return final;
    }
};
// TC: O(N) SC: O(N)

// Stack+Level Vector per Level
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        stack<int> st;
        while(!q.empty()){
            vector<int> level;
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* node = q.front();
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                level.push_back(node->data);
            }
            for(int i=level.size()-1; i>=0; i--){
                st.push(level[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
// TC: O(N) SC: O(N)


//* Optimized & Clean Approach (Direct Stack Push)
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        queue<Node*> q;
        stack<int> st;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n; i++){
                Node* node = q.front();
                q.pop();
                st.push(node->data);
                if(node->right != nullptr) q.push(node->right);
                if(node->left != nullptr) q.push(node->left);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
// TC: O(N) SC: O(N)
