class Solution {
  private:
    bool isLeaf(Node* root){
        return (!root->left) && (!root->right);
    }
    vector<int> addLeftBoundary(Node* root, vector<int>& res){
        Node* curr = root->left;
        while(curr){
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left != nullptr) curr = curr->left;
            else curr = curr->right;
        }
        return res;
    }
    vector<int> addRightBoundary(Node* root, vector<int>& res){
        vector<int> temp;
        Node* curr = root->right;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right != nullptr) curr = curr->right;
            else curr = curr->left;
        }
        reverse(temp.begin(), temp.end());
        res.insert(res.end(), temp.begin(), temp.end());
        return res;
    }
    void addLeaves(Node* root, vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left) addLeaves(root->left, res);
        if(root->right) addLeaves(root->right, res);
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> res;
        if(root == nullptr) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};

//* Time Complexity: O(H) + O(H) + O(N) = O(N), where H is the height of the tree and N is the number of nodes in the tree.
//* Space Complexity: O(N) in the worst case when all nodes are leaves.
// Space used by the output vector is not considered in space complexity analysis.