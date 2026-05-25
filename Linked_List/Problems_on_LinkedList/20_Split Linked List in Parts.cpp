class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        if(head == NULL) return ans;
        ListNode* temp = head;
        int n = 1;
        while(temp->next){
            temp = temp->next;
            n++;
        }
        int block = n / k;
        int extra = n % k;
        temp = head;
        int i = 0;
        while(temp){
            int size = block + (i < extra ? 1 : 0);
            ListNode* tail = temp;

            for(int j = 0; j < size-1; j++){
                if(tail == NULL) break;
                tail = tail->next;
            }

            ListNode* nextNode = ((tail != NULL) ? tail->next : NULL);
            if(tail != NULL) tail->next = NULL;
            
            ans[i] = temp;
            temp = nextNode;
            i++;
        }
        return ans;
    }
};
// Time Complexity: O(n) where n is the number of nodes in the linked list
// Space Complexity: O(k) for the output vector.