//* Preorder Inorder Postorder Traversals in One Traversal

vector<int> preInPostTraversal(TreeNode* root) {
    vector<int> pre, in, post;
    if(root == NULL) return {};
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        TreeNode* node = it.first;
        int num = it.second;
        if(num == 1){
            pre.push_back(node->val);
            it.second++;
            st.push(it);
            if(node->left != NULL){
                st.push({node->left, 1});
            }
        }
        else if(num == 2){
            in.push_back(node->val);
            it.second++;
            st.push(it);
            if(node->right != NULL){
                st.push({node->right, 1});
            }
        }
        else{
            post.push_back(node->val);
        }
    }
    vector<int> ans;
    ans.insert(ans.end(), pre.begin(), pre.end());
    ans.insert(ans.end(), in.begin(), in.end());
    ans.insert(ans.end(), post.begin(), post.end());
    return ans;
}