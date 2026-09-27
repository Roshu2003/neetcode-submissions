class Node {
    public:
    string s;
    vector<Node*> child;
    Node() : child(26,nullptr) , s(""){}
};
class Solution {
public:
    Node* root = new Node();
    void add(string s){
        Node* curr = root;
        for(auto c : s){
            int idx = c - 'a';
            if(curr -> child[idx] == nullptr){
                curr -> child[idx] = new Node();
            }
            curr = curr ->child[idx];
        }
        curr -> s = s;
    }
    vector<vector<char>> v;
    vector<string> ans;
    void dfs(int i ,int j,Node* curr){
        int n = v.size();
        int m = v[0].size();
        if(i >= n || j >= m || i < 0 || j < 0 || v[i][j] == '#')return;
        
        char ch = v[i][j];
        int idx = ch - 'a';
        // curr idx is present or no
        if(curr -> child[idx] == nullptr)return;
        curr = curr -> child[idx];

        if(curr -> s != "" ){
            ans.push_back(curr -> s);
            curr -> s = "";
        };

        v[i][j] = '#';
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int k = 0; k < 4; k++){
            int nr = i + dx[k];
            int nc = j + dy[k];
            dfs(nr,nc,curr);
        }
        v[i][j] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        v = board;
        // Node* curr = root;
        for(auto it : words){
            add(it);
        }
        int n = v.size();
        int m = v[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(i,j,root);
            }
        }
        return ans;
    }
};
