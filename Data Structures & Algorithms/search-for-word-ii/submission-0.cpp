class Solution {
public:
    class Node{
        public:
        Node* child[26];
        string s;
        Node(){
            for(int i = 0; i <26; i++)child[i] = NULL;
            s = "";
        }
    };
    Node* root = new Node();

    void add(string &t){
        Node* curr = root;
        for(auto it : t){
        int id = it - 'a';
        if(!curr->child[id])curr->child[id] = new Node();
        curr = curr->child[id];
        }
        curr->s = t;
    }
    vector<string> ans;
    vector<vector<char>> v;
    void dfs(int i,int j,Node* node){
        int n = v.size();
        int m = v[0].size();
        //check is boud condition
        if(i < 0 || j < 0 ||  i >= n || j >= m || v[i][j] == '#')return;

        char ch = v[i][j];

        if(node->child[ch - 'a'] == NULL)return;

        node = node->child[ch - 'a']; // move to the last so that we can check if there is a worsd or not

        if(node->s != ""){
            ans.push_back(node->s);
            node -> s = "";//avoid dublicate
        }

        v[i][j] = '#'; // visit mark
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int x = 0; x < 4; x++){
            dfs(i + dx[x],j + dy[x],node);
        }
        v[i][j] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        v = board;
        for(auto it : words){
            add(it);
        }
        int n = v.size();
        int m = v[0].size();
        for(int i = 0; i < n ;i++){
            for(int j = 0;j  < m; j++){
                dfs(i,j,root);
            }
        }
        return ans;
    }
};
