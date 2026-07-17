class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_set<int> vis;
    bool dfs(int node){
        if(vis.count(node))return true;
        vis.insert(node);
        for(auto it : adj[node]){
            if(dfs(it))return true;
        }
        vis.erase(node);
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edg) {
        for(int i = 0; i < n; i++){
            adj[i] = {};
        }
        for(auto it : edg){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        for(int i = 0; i < n; i++){
            if(dfs(i))return false;
        }
        return true;
    }
};
