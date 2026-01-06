class LRUCache {
public:
    
    class Node{ //Doubly Linked list
        public:
        int key,val;
        Node* prev;
        Node * next;

        Node(int k,int v){
            key =k;
            val =v;
        }
    };
    //Initially setting the value to -1
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    unordered_map<int,Node*> mp; //Searching the val according to corrsponding node
    int limit;

    void addNode(Node* newNode){
        Node* oldNext = head->next;
        head->next = newNode;
        oldNext->prev = newNode;
        newNode->next = oldNext;
        newNode->prev = head;
    }

    void deleteNode(Node* newNode){
        Node* oldPrev = newNode->prev;
        Node* oldNext = newNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity; //Initialize the limit;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
       if(mp.find(key)==mp.end()) return -1;

       Node* ansNode = mp[key];
       int ans = ansNode->val;

       mp.erase(key);
       deleteNode(ansNode);
       addNode(ansNode);
       mp[key] = ansNode;
       return ans; 
    }
    
    void put(int key, int value) {
        // 1) When the key already exist , then deletes it from the DLL and map
        if(mp.find(key) != mp.end()){ 
            Node* oldNode = mp[key];
            deleteNode(oldNode);
            mp.erase(key);
        }

        // 2) Delete LRU node, when the LRU cache recahes the limit
        if(mp.size()==limit){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        // 3) When the newNode is created 
        Node* newNode = new Node(key,value);
        addNode(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */