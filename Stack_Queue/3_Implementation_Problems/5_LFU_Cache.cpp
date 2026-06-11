class LFUCache {
public:
    class Node{
    public:
        int key;
        int val;
        int freq;
        Node* next;
        Node* prev;

        Node(int k, int v){
            key = k;
            val = v;
            freq = 1;
            next = nullptr;
            prev = nullptr;
        }
    };

    class List{
    public:
        Node* head;
        Node* tail;
        int size;

        List(){
            size = 0;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;
        }

        void addNodeAfterHead(Node* newNode){
            Node* currNode = head->next;

            head->next = newNode;
            newNode->prev = head;

            newNode->next = currNode;
            currNode->prev = newNode;

            size++;
        }

        void deleteNode(Node* node){
            Node* prevNode = node->prev;
            Node* nextNode = node->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            size--;
        }
    };

    unordered_map<int, List*> freqList;
    unordered_map<int, Node*> keyNode;
    int minFreq;
    int currSize;
    int cap;

    LFUCache(int capacity) {
        currSize = 0;
        minFreq = 0;
        cap = capacity;
    }

    void updateFreq(Node* node){
        int freq = node->freq;
        freqList[freq]->deleteNode(node);

        if(freq == minFreq && freqList[freq]->size == 0){
            minFreq++;
        }

        node->freq++;
        if(freqList.find(node->freq) == freqList.end()){
            freqList[node->freq] = new List();
        }

        freqList[node->freq]->addNodeAfterHead(node);
    }
    
    int get(int key) {
        if(keyNode.find(key) == keyNode.end()) return -1;
        
        Node* node = keyNode[key];
        int value = node->val;

        updateFreq(node);        

        return value;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;

        if(keyNode.find(key) != keyNode.end()){
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
        }
        else{
            if(currSize == cap){
                List* list = freqList[minFreq];
                Node* victim = list->tail->prev;
                list->deleteNode(victim);
                keyNode.erase(victim->key);
                delete victim;
                currSize--;
            }

            Node* newNode = new Node(key, value);
            if(freqList.find(1) == freqList.end()){
                freqList[1] = new List();
            }
            freqList[1]->addNodeAfterHead(newNode);
            minFreq = 1;
            currSize++;
            keyNode[key] = newNode;
        }
    }
};

//* get(key): O(1)
//* put(key, value): O(1)
//* Space Complexity: O(capacity)