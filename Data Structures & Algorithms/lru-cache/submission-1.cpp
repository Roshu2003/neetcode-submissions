class Node {
    public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k,int v) : key(k) , val(v), prev(nullptr) , next(nullptr){}
};

class LRUCache {
public:
    int n;
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;
    LRUCache(int capacity) {
        n = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left -> next = right;
        right -> prev = left;
    }
    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right -> prev = node;
    }
    void remove(Node* node){
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }
    int get(int key) {
        if(cache.find(key) == cache.end())return -1;

        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }

        Node* newNode = new Node(key,value);
        cache[key] = newNode;
        insert(newNode);
        if(cache.size() > n){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
