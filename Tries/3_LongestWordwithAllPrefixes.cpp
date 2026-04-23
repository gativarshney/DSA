struct Node{
    Node* links[26] = {nullptr};
    bool flag = false;
    
    bool containsKey(char ch){
        return (links[ch - 'a'] != nullptr);
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    bool checkIfPrefixExist(string &word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
            if(node->isEnd() == false) return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        Trie trie;
        for(int i=0; i<words.size(); i++){
            trie.insert(words[i]);
        }
        string longest = "";
        for(auto &it : words){
            if(trie.checkIfPrefixExist(it)){
                if(it.length() > longest.length()){
                    longest = it;
                }
                else if(it.length() == longest.length() && it < longest){
                    longest = it;
                }
            }
        }
        return longest;
    }
};
// Time Complexity: O(n*m) where n is the number of words and m is the average length of the words. O(n*m) for inserting all the words in the trie and O(n*m) for checking if the prefix exists for each word.
// Space Complexity: O(n*m) for the trie where n is the number of words and m is the average length of the words. O(1) for the longest string.