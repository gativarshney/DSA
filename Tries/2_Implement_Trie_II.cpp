#include<bits/stdc++.h>
struct Node{
    Node* links[26] = {nullptr};
    int cntPrefix = 0;
    int cntEndWith = 0;
    bool containsKey(char ch){
        return (links[ch - 'a'] != nullptr);
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
    }
};

class Trie{
private:
    Node *root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->getEnd();
    }
    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(!node->containsKey(word[i])) return 0;
            node = node->get(word[i]);
        }
        return node->getPrefix();
    }
    void erase(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else return;
        }
        node->deleteEnd();
    }
};
