vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>> listOfPairs;   
    Node* t1 = head; 
    while(t1 != nullptr){
        Node* t2 = t1->next;
        while(t2 != nullptr){
            int val = t1->data + t2->data;
            if(val == k){
                listOfPairs.push_back({t1->data, t2->data});
            }
            else if(val > k) break;
            t2 = t2->next; 
        }
        t1 = t1->next;
    }
    return listOfPairs;
}
// TC: O(N * N) SC: O(1)

//*************************************** */

Node* findTail(Node* head){
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp;
}

vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>> listOfPairs;   
    if(head == nullptr) return listOfPairs;
    Node* left = head; 
    Node* right = findTail(head);
    while(left->data < right->data){
        int val = left->data + right->data;
        if(val == k){
            listOfPairs.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;

        }
        else if(val > k) right = right->prev;
        else left = left->next;

    }
    return listOfPairs;
}
// TC: O(2*N) SC: O(1)