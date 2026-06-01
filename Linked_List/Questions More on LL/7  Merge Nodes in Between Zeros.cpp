class Solution {
private:
    void removeTail(ListNode* head){
        ListNode* temp = head;

        while(temp->next->next != NULL){
            temp = temp->next;
        }
        temp->next = NULL;
    }
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp = head->next;
        ListNode* prev = head;
        int sum  = 0;

        while(temp != NULL){
            if(temp->val == 0){
                prev = temp;
                temp = temp->next;
            }
            while(temp != NULL && temp->val != 0){
                sum += temp->val;
                temp = temp->next;
            }
            prev->val = sum;
            sum = 0;
            prev->next = temp;
        }

        removeTail(head);

        return head;
    }
};