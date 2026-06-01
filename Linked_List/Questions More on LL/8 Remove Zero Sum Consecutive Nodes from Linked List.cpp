class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> mpp;
        ListNode* dummy = new ListNode(0, head);
        mpp[0] = dummy;
        ListNode* temp = head;
        int sum = 0;

        while(temp){
            sum += temp->val;

            if(mpp.find(sum) != mpp.end()){
                ListNode* prev = mpp[sum];

                ListNode* curr = prev->next;
                int tempSum = sum;
                while(curr != temp){
                    tempSum += curr->val;
                    mpp.erase(tempSum);
                    curr = curr->next;
                }
                prev->next = temp->next;
            }
            else mpp[sum] = temp;

            temp = temp->next;
        }

        return dummy->next;
    }
};