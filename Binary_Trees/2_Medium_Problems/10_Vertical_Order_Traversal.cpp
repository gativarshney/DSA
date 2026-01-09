class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;        //1st int : vertical level
                                                        //2nd int : horizontal level (level order)
                                                        //multiset<int> : node values at that position (automatically sorted)
        queue<pair<TreeNode*, pair<int, int>>> todo;    //node, {x coordinate, y coordinate}
        todo.push(root, {0,0});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;   // current node
            int x = p.second.first;     // vertical level
            int y = p.second.second;    // horizontal level
            nodes[x][y].insert(node->val);      // insert node value at (x,y)
            if(node->left){
                todo.push(node->left, {x-1, y+1});  // left child at (x-1, y+1)
            }
            if(node->right){
                todo.push(node->right, {x+1, y+1}); // right child at (x+1, y+1)
            }
        }
        vector<vector<int>> ans;
        for(auto p : nodes){    // iterate over vertical levels
            vector<int> col;
            for(auto q : p.second){  // iterate over horizontal levels  
                col.insert(col.end(), q.second.begin(), q.second.end());    // q.second is a multiset of node values
            }
            ans.push_back(col); // add the column to the answer
        }
        return ans;
    }
};

// Time Complexity: O(N log N) {logN due to multiset insertions}
// Space Complexity: O(N) + O(N) {for map and queue}