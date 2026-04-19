class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int frogs = 0;
        int maxFrogs = 0;
        vector<int> count(5, 0);
        for(char ch : croakOfFrogs){
            if(ch == 'c'){
                frogs++;
                maxFrogs = max(maxFrogs, frogs);
                count[0]++;
            }
            else if(ch == 'r'){
                if(count[0] == 0) return -1;
                count[0]--;
                count[1]++;
            }
            else if(ch == 'o'){
                if(count[1] == 0) return -1;
                count[1]--;
                count[2]++;
            }
            else if(ch == 'a'){
                if(count[2] == 0) return -1;
                count[2]--;
                count[3]++;
            }
            else if(ch == 'k'){
                if(count[3] == 0) return -1;
                count[3]--;
                count[4]++;
                frogs--;
            }
            else{
                return -1;
            }
        }
        if(frogs != 0) return -1;
        return maxFrogs;
    }
};
// Time Complexity: O(n) where n is the length of the input string, since we are iterating through the string once.
// Space Complexity: O(1) since we are using a fixed amount of space to store the count of each character and the number of frogs.
//* We keep track of the count of each character in the word "croak" and the number of frogs currently croaking. Whenever we encounter a 'c', we increment the number of frogs and update the maximum number of frogs if necessary. For each subsequent character, we check if the previous character in the sequence has been counted, and if so, we decrement the count of the previous character and increment the count of the current character. If we encounter a 'k', we also decrement the number of frogs since one frog has finished croaking. If at any point we encounter an invalid character or if there are still frogs croaking at the end, we return -1. Otherwise, we return the maximum number of frogs needed to produce the given croak sequence. 
//? And also in the end check is there are any frogs still croaking, if so return -1 since it means the sequence is incomplete. Ex: croa -> return -1 since there is a frog that started croaking but did not finish. 