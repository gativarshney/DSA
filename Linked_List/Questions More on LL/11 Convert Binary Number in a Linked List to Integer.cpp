// Appraoch 1: Using String
class Solution {
private:
    long long binaryToDecimal(string &s){
        long long ans = 0;
        long long power = 1;
        for(int i = s.size()-1; i >= 0; i--){
            ans += (s[i] - '0') * power;
            power *= 2;
        }

        return ans;
    }
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string s = "";

        while(temp){
            s += (temp->val + '0');
            temp = temp->next;
        }

        return binaryToDecimal(s);
    }
};

// Approach 2: Using Bit Manipulation
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        int ans = 0;

        while(temp){
            ans = ans * 2 + temp->val;
            temp = temp->next;
        }

        return ans;
    }
};