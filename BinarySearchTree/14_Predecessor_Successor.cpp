class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        vector<Node*> ans;
        Node* pre = NULL;
        Node* suc = NULL;
        Node* temp = root;
        while(temp != NULL){
            if(temp->data < key){
                pre = temp;
                temp = temp->right;
            }
            else temp = temp->left;
        }
        ans.push_back(pre);
        Node* curr = root;
        while(curr != NULL){
            if(curr->data > key){
                suc = curr;
                curr = curr->left;
            }
            else curr = curr->right;
        }
        ans.push_back(suc);
        return ans;
    }
};
// Time Complexity: O(h) where h is the height of the tree
// Space Complexity: O(1)