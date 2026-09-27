class Node {
    public:
    bool isEnd;
    vector<Node*> child;
    Node() : isEnd(false),child(26,nullptr){}
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(auto c : word){
            int idx = c - 'a';
            if(curr -> child[idx] == nullptr){
                curr -> child[idx] = new Node();
            }
            curr = curr -> child[idx];
        }
        curr->isEnd  = true;
    }
    bool dfs(int i,string &s,Node* curr){
        // Node* curr = root;
        if(i == s.size())return curr -> isEnd;

        //case 1 if curr char is .at(if(s[i]))
        if(s[i] == '.'){
            for(int j = 0; j < 26; j++){
                if(curr -> child[j] != nullptr){
                    if(dfs(i + 1,s,curr -> child[j])) return true;
                }
            }
            return false;
        }
        // case 2 not a .
        int idx = s[i] - 'a';
        if(curr -> child[idx] == nullptr)return false;

        return dfs(i + 1,s,curr -> child[idx]);

    }
    bool search(string word) {
        return dfs(0,word,root);
    }
};
