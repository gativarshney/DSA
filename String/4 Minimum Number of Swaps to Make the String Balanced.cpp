class Solution {
public:
    int minSwaps(string s) {
        int open = 0, close = 0;

        for(char &ch : s){
            if(ch == '[') open++;
            else{
                if(open > 0) open--;
                else close++;
            }
        }

        return (open + 1) / 2;
    }
};

//! Why (open + 1) / 2 ? --> Because, Each swap can fix two unmatched brackets.

// A useful fact to remember for this problem is:

// After the scan, open == close.
// Minimum swaps = ceil(unmatched / 2) = (unmatched + 1) / 2.

// ]]][[[ --> ans = 2 