class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();

        int i = 0;
        int ans = 0;

        while(i < n){
            if(s[i] == ' ') i++;
            else break;
        }

        bool isNegative = (s[i] == '-' ? true : false);
        bool isPositive = (s[i] == '+') ? true : false;

        if(isNegative || isPositive) i++;

        while(i < n){
            if(s[i] == '0') i++;
            else break;
        }

        while(i < n){
            char ch = s[i];

            if(ch >= '0' && ch <= '9'){
                int digit = ch - '0';

                if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)){
                    return isNegative ? INT_MIN : INT_MAX;
                }

                ans = ans * 10 + digit;
            }
            else{
                break;
            }

            i++;
        }

        if(isNegative) ans = ans * -1;

        return ans;
    }
};

//* TC: O(N) SC: O(1)

/*
Overflow Check (Very Important)

We must check for overflow BEFORE doing:
    ans = ans * 10 + digit;

Otherwise, ans may overflow and produce undefined behavior.

INT_MAX = 2147483647
INT_MIN = -2147483648

Case 1:
If ans > INT_MAX / 10,
then multiplying by 10 itself will exceed the integer limit.

Case 2:
If ans == INT_MAX / 10,
the last digit determines whether it overflows.

For positive numbers:
    Last digit can be at most 7 (2147483647).
    If digit > 7, return INT_MAX.

For negative numbers:
    Last digit can be at most 8 (2147483648).
    If digit > 8, return INT_MIN.

Condition:
if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)){
    return isNegative ? INT_MIN : INT_MAX;
}
*/