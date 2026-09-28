class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = 1e9;
        vector<vector<pair<int,int>>> adj(n);
        vector<vector<int>> dist(n,vector<int>(k + 5,INF));
        for(auto it : flights){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({0,src,0});
        while(!pq.empty()){
            auto [cost,node,stop] = pq.top();
            pq.pop();
            if(node == dst)return cost;
            if(k + 1 == stop || dist[node][stop] < cost)continue;

            for(auto &[nei,wt] : adj[node]){
                int newCost = wt + cost;
                int nextStop = stop + 1;
                if(dist[nei][nextStop] > newCost){
                    dist[nei][nextStop] = newCost;
                    pq.push({newCost,nei,nextStop});
                }
            }
        }
        return -1;
    }
};
