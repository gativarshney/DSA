//! Brute force
class Solution {
  public:
    int countSubs(string& s) {
        unordered_set<string> st;
        for(int i=0; i<s.size(); i++){
            string str = "";
            for(int j=i; j<s.size(); j++){
                str += s[j];
                st.insert(str);
            }
        }
        return st.size();
    }
};
// Time Complexity: O(n^2) where n is the length of the string. O(n^2) for generating all possible substrings and O(1) for inserting each substring in the unordered set. Overall O(n^2).
// Space Complexity: O(n^3) for the unordered set where n is the length of the string. O(n^2) for storing all possible substrings and O(n) for each substring. Overall O(n^3).

//! Optimal Code using Trie
struct Node{
    Node* links[26] = {nullptr};

    // Destructor to free memory
    ~Node() {
        for (int i=0; i<26; ++i) {
            delete links[i];
        }
    }

    bool containsKey(char ch){
        return (links[ch - 'a'] != nullptr);
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
};
class Solution {
public:
    int countSubs(string& s) {
        int cnt = 0;
        Node* root = new Node();
        for(int i=0; i<s.size(); i++){
            Node* node = root;
            for(int j=i; j<s.size(); j++){
                char ch = s[j];
                if(!node->containsKey(ch)){
                    node->put(ch, new Node());
                    cnt++;
                }
                node = node->get(ch);
            }
        }
        return cnt;
    }
};
// Time Complexity: O(n^2) where n is the length of the string. O(n^2) for generating all possible substrings and O(1) for inserting each substring in the trie. Overall O(n^2).
// Space Complexity: O(n^2) in the worst case when all substrings are unique, leading to creation of O(n^2) trie nodes