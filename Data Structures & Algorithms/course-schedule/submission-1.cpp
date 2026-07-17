class Solution {
public://O(E + V);
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
        vector<int> ind(n,0);
        for(auto it : edg){
            int u = it[0];
            int v = it[1];
            ind[v]++;
            adj[u].push_back(v);
        }
        int cnt = 0;
        // for(int i = 0; i < n; i++){
        //     if(dfs(i))return false;
        // }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            cnt++;
            for(auto it : adj[node]){
                if(--ind[it] == 0)q.push(it);
            }
        }
        return cnt == n;
    }
};
