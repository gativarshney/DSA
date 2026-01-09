class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        map<int, int> mpp;
        queue<pair<int, Node*>>q;
        q.push({0, root});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int line = it.first;
            Node* node = it.second;
            mpp[line] = node->data;
            if(node->left != NULL) q.push({line-1, node->left});
            if(node->right != NULL) q.push({line+1, node->right});
        }
        for(auto it: mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
// Time Complexity: O(N log N) {logN due to map insertions}
// Space Complexity: O(N) + O(N) {for map and queue}

//! Another approach using unordered_map and tracking min and max horizontal distances (less time complexity)
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        unordered_map<int, int> mpp;
        queue<pair<int, Node*>>q;
        q.push({0, root});
        int mini = 0, maxi = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int line = it.first;
            Node* node = it.second;
            mpp[line] = node->data;
            mini = min(mini, line);
            maxi = max(maxi, line);
            if(node->left != NULL) q.push({line-1, node->left});
            if(node->right != NULL) q.push({line+1, node->right});
        }
        for(int i=mini; i<=maxi; i++){
            if(mpp.find(i) != mpp.end()){
                ans.push_back(mpp[i]);
            }
        }
        return ans;
    }
};
// Time Complexity: O(N) {as unordered_map has average O(1) insertion time}
// Space Complexity: O(N) + O(N) {for unordered_map and queue}

//! NOTE:
//* In both approaches, we use level order traversal (BFS) to ensure that we visit nodes level by level.
//* Recursive DFS may not yield correct results for bottom view as it might overwrite deeper nodes with shallower ones at the same vertical line.