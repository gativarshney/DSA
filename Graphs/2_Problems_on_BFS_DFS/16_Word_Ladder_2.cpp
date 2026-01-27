class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return {};
        queue<vector<string>> q;
        q.push({beginWord});
        int level = 0;
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        vector<vector<string>> ans;
        while(!q.empty()){
            vector<string> vec = q.front();
            q.pop();
            string word = vec.back();
            if(vec.size() > level){
                level++;
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();
            }
            if(word == endWord){
                if(ans.size() == 0){
                    ans.push_back(vec);
                }
                else if(vec.size() == ans[0].size()){
                    ans.push_back(vec);
                }
                else if(vec.size() > ans[0].size()){
                    break;
                }
            }
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();

                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};
//! NOTE:
//* Time Complexity is unpredictable as it depends on the number of possible transformations and the structure of the word list.
//* Leetcode submission will give memory limit exceeded as test cases are extremely difficult and reuire complex optimizations like competitive programming. 
//* But, it is best for interview purposes.