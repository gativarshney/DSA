class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;
            Node(int k, int v){
                key = k;
                val = v;
            }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> mpp;
    int cap;

    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }

    void addNodeAfterHead(Node* newNode){
        Node* currNext = head->next;
        head->next = newNode;
        newNode->next = currNext;
        newNode->prev = head;
        currNext->prev = newNode;
    }

    void deleteNode(Node* node){
        Node* nextNode = node->next;
        Node* prevNode = node->prev;
        nextNode->prev = prevNode;
        prevNode->next = nextNode;
    }
    
    int get(int key) {
        if(mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        int value = node->val;
        deleteNode(node);
        addNodeAfterHead(node);
        return value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key) != mpp.end()){
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            addNodeAfterHead(node);
        }
        else{
            if(mpp.size() == cap){
                Node* lastNode = tail->prev;
                deleteNode(lastNode);
                mpp.erase(lastNode->key);
                delete(lastNode);
            }
            Node* newNode = new Node(key, value);
            addNodeAfterHead(newNode);
            mpp[key] = newNode;
        }
    }
};
//* get(key): O(1)
//* put(key, value): O(1)
//* Space Complexity: O(capacity)