// Using concept of Sliding Window

class Solution {
private:
    bool isEqual(vector<int> cnt1, vector<int> cnt2){
        for(int i=0; i<cnt1.size(); i++){
            if(cnt1[i] != cnt2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        vector<int> count1(26, 0), count2(26, 0);
        for(int i=0; i<s1.size(); i++){
            count1[s1[i] - 'a']++;
        }
        int windowSize = s1.length(), i = 0;
        while(i < windowSize && i < s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        if(isEqual(count1, count2)) return true;
        while(i < s2.length()){
            char newChar = s2[i];
            int indexToAdd = newChar - 'a';
            count2[indexToAdd]++;

            char oldChar = s2[i - windowSize];
            int indexToRemove = oldChar - 'a';
            count2[indexToRemove]--;

            i++;
            
            if(isEqual(count1, count2)){
                return true;
            }
        }
        return false;
    }
};