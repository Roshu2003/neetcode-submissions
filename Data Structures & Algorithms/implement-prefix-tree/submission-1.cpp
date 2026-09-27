class Node {
    public:
    Node* child[26];
    int isEnd;
    Node(){
        isEnd = false;
        for(int i = 0; i < 26; i++){
            child[i]  = nullptr;
        }
    }
};
class PrefixTree {
public:
    Node* root;
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(auto c : word){
            int idx = c - 'a';
            if(curr->child[idx] == nullptr){
                curr -> child[idx] = new Node();
            }
            curr = curr -> child[idx];
        }
        curr -> isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(auto c : word){
            int idx = c - 'a';
            if(curr -> child[idx] == nullptr)return false;
            curr = curr -> child[idx];
        }
        return curr -> isEnd;
    }
    
    bool startsWith(string prefix) {
        Node * curr = root;
        for(auto c : prefix){
            int idx = c - 'a';
            if(curr -> child[idx] == nullptr)return false;
            curr = curr -> child[idx];
        }
        return true;
    }
};
