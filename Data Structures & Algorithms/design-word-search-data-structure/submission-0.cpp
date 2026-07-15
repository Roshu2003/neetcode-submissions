class WordDictionary {
public:

    class Node{
    public:

        Node* child[26];
        bool isEnd;

        Node(){

            isEnd = false;

            for(int i=0;i<26;i++)
                child[i]=nullptr;
        }
    };


    Node* root;


    WordDictionary(){
        root = new Node();
    }


    void addWord(string word){

        Node* curr = root;

        for(char c: word){

            int idx = c-'a';

            if(curr->child[idx] == nullptr)
                curr->child[idx] = new Node();

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }


    bool dfs(Node* node, int i, string &word){

        if(i == word.size())
            return node->isEnd;


        char c = word[i];


        // wildcard case
        if(c == '.'){

            for(int j=0;j<26;j++){

                if(node->child[j] &&
                   dfs(node->child[j], i+1, word))
                {
                    return true;
                }
            }

            return false;
        }


        // normal character
        int idx = c-'a';

        if(node->child[idx] == nullptr)
            return false;


        return dfs(node->child[idx], i+1, word);
    }


    bool search(string word){

        return dfs(root,0,word);
    }
};