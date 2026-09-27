class DSU {
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int node){
        if(node != parent[node])parent[node] = find(parent[node]);
        return parent[node];
    }
    bool add(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)return false;
        if(size[pu] >= size[pv]){
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else{
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return true;
    }
    int getSize(int node){
        return size[find(node)];
    }
};
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int ans = 0;
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        DSU dsu(n * m);
        auto index = [&](int i,int j){
            return i * m + j;
        };
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == 1){
                    for(auto d : dir){
                        int nr = i + d[0];
                        int nc = j + d[1];
                        if(nr >= 0 && nc < m && nr < n && nc >= 0 && v[nr][nc] == 1){
                            dsu.add(index(i,j),index(nr,nc));
                        }
                    }
                    ans = max(ans,dsu.getSize(index(i,j)));
                }
            }
        }
        return ans;
    }
};
