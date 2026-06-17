class Solution {
    bool isPalindrome(string s){
        string rev = s;
        reverse(rev.begin(), rev.end());
        return (s == rev);
    }

    void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans){
        if(s.empty()){
            ans.push_back(partitions);
            return;
        }

        for(int i = 0; i < s.size(); i++){
            string part = s.substr(0, i+1);
            if(isPalindrome(part)){
                partitions.push_back(part);
                getAllParts(s.substr(i+1), partitions, ans);
                partitions.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);

        return ans;
    }
};
// Time Complexity: O(2^N * N) where N is the length of the string. This is because in the worst case, we might have to check all possible partitions, and for each partition, we might have to reverse the string to check if it's a palindrome.
// Space Complexity: O(N^2) for the recursive call stack and the storage of all partitions.