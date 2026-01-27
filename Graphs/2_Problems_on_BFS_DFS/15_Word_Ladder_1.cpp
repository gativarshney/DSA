class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return 0;
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            if(word == endWord) return steps;
            q.pop();
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch='a'; ch<='z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        q.push({word, steps + 1});
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};
//* Time Complexity: O(N * L * 26) where N is number of words and L is length of each word
//* Space Complexity: O(N) for the unordered_set

//! NOTE: "Erase visited words from the set to avoid revisits"
//* This implementation uses BFS to find the shortest transformation sequence from beginWord to endWord.
//? We have used set here as a visited structure to keep track of words that have already been processed.
//* The use of an unordered_set allows for O(1) average time complexity for lookups and deletions.