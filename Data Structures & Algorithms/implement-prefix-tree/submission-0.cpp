class Node{
    public:
    Node* child[26];
    bool isEnd;
    Node(){
        isEnd = false;
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
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
            if(curr->child[idx] == NULL){
                curr -> child[idx] = new Node();//create node for the new char
            }
            curr = curr->child[idx];
        }
        curr->isEnd = true;//mark the end of the word 
    }
    
    bool search(string word) {
        Node* curr = root;
        for(auto c : word){
            if(curr->child[c - 'a'] == NULL)return false;
            curr = curr->child[c - 'a'];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(auto c : prefix){
            int idx = c - 'a';
            if(curr -> child[idx] == NULL){
                return false;
            }
            curr = curr->child[idx];
        }
        return true;
    }
};
