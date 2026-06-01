class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr){
            int gcd = __gcd(prev->val, curr->val);
            ListNode* newNode = new ListNode(gcd);

            prev->next = newNode;
            newNode->next = curr;

            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};