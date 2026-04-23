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

class Trie {
private:
    Node *root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i=0; i<prefix.size(); i++){
            if(!node->containsKey(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};
// Time Complexity: O(n) for insert, O(n) for search and O(n) for startsWith where n is the length of the word or prefix.
// Space Complexity: O(n) for insert where n is the length of the word. O(1) for search and startsWith.