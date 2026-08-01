// Given a string s consisting only of characters a, b and c. Return the number of substrings containing at least one occurrence of all these characters a, b and c.

// ? Brute Force; TC: O(N*N) SC:O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            int count[3] = {0, 0, 0};
            for(int j=i; j<n; j++){
                if(s[j] == 'a') count[0]++;
                if(s[j] == 'b') count[1]++;
                if(s[j] == 'c') count[2]++;
                if(count[0] > 0 && count[1] > 0 && count[2] > 0){
                    cnt += (n - j);
                    break;
                }
            }
        }
        return cnt;
    }
};

//? Optimal; TC:O(N) SC: O(1)
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int lastSeen[3] = {-1, -1, -1};
        int cnt = 0;
        for(int i=0; i<n; i++){
            lastSeen[s[i] - 'a'] = i;
            if(lastSeen[0] >= 0 && lastSeen[1] >= 0 && lastSeen[2] >= 0){
                int minIndex = min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
                cnt += minIndex + 1;
            }
        }
        return cnt;
    }
};