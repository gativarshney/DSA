class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        
        Node* temp = root;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();

                if(i < size-1) node->next = q.front();
                else node->next = NULL;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return root;
    }
};

// Approach 2: Using O(1) Space
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;

        Node* leftMost = root;

        while(leftMost->left){
            Node* curr = leftMost;

            while(curr){
                curr->left->next = curr->right;

                if(curr->next){
                    curr->right->next = curr->next->left;
                }

                curr = curr->next;
            }
            leftMost = leftMost->left;
        }

        return root;
    }
};
