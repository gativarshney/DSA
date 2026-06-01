/*
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//! Brute Force
Node* copyRandomList(Node* head) {
    if(head == NULL) return NULL;

    Node* cloneHead = new Node(head->val);
    Node* cloneTail = cloneHead;
    Node* temp = head->next;

    while(temp != NULL){
        Node* newNode = new Node(temp->val);
        cloneTail->next = newNode;
        cloneTail = newNode;
        temp = temp->next;
    }

    Node* originalNode = head;
    Node* cloneNode = cloneHead;

    while(originalNode != NULL && cloneNode != NULL){
        if(originalNode->random != NULL){
            int randomIndex = 0;
            Node* temp1 = head;

            while(temp1 != originalNode->random){
                temp1 = temp1->next;
                randomIndex++;
            }

            Node* temp2 = cloneHead;
            for(int i=0; i<randomIndex; i++){
                temp2 = temp2->next;
            }
            cloneNode->random = temp2;
        }
        else{
            cloneNode->random = NULL;
        }
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}
// TC: O(n^2)) SC: O(n)


//! Better Approach
class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int nodeVal){
        Node* newNode = new Node(nodeVal);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        unordered_map<Node*, Node*> oldToNew;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL){
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode != NULL){
            cloneNode->random = oldToNew[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};

// TC: O(n) where n is the number of nodes in the linked list.
// SC: O(n) as we are using a hash map to store the mapping of original nodes to their corresponding cloned nodes.

//? Steps:
//? 1. Create a clone of the original linked list without considering the random pointers.
//? 2. Create a hash map to store the mapping of original nodes to their corresponding cloned nodes.
//? 3. Traverse the original linked list again and update the random pointers of the cloned nodes using the hash map.


//! Optimal Approach

class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int nodeVal){
        Node* newNode = new Node(nodeVal);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL){
            Node* nextNode = originalNode->next;
            Node* nextClone = cloneNode->next;
            
            originalNode->next = cloneNode;
            cloneNode->next = nextNode;

            originalNode = nextNode;
            cloneNode = nextClone;
        }

        temp = head;
        while(temp != NULL){
            if(temp->next != NULL){
                temp->next->random = temp->random ?  temp->random->next : temp->random;
            }
            else{
                temp->next = temp->random;
            }
            temp = temp->next->next;
        }

        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode != NULL && cloneNode != NULL){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if(originalNode != NULL){
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};

// TC: O(n) where n is the number of nodes in the linked list.
// SC: O(1) as we are not using any extra space.

//? Steps:
//? 1. Create a clone of the original linked list 
//? 2. Insert the cloned nodes between the original nodes.
//? 3. Update the random pointers of the cloned nodes.
//? 4. Separate the original and cloned lists.