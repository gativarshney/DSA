struct Node{
    Node *links[26] = {nullptr};
    bool flag = false;
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    bool dfs(string &word, int idx, Node* node){
        if(idx == word.size()) return node->isEnd();
        if(word[idx] == '.'){
            for(int i=0; i<26; i++){
                Node* next = node->links[i];
                if(next && dfs(word, idx+1, next)) return true;
            }
        }
        else{
            if(!node->containsKey(word[idx])) return false;
            node = node->get(word[idx]);
            if(dfs(word, idx+1, node)) return true;
        }
        return false;
    }

    void addWord(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};
/*
addWord:
    Time: O(L)
    Space: O(L) per insertion (overall O(N·L))

search:
    Time:
        O(L) if no '.'
        O(26^k · L) if k dots
    Space:
        O(L) recursion stack

Trie storage:
    O(N · L)
*/