class DSU {
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int node){
        if(node != parent[node]) parent[node] = find(parent[node]);
        return parent[node];
    }

    bool Union(int u,int v){
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
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        DSU ds(n * m);
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        auto index = [&](int r, int c) {
            return r * m + c;
        };
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    for(auto &d : dir){
                        int nr = i + d[0];
                        int nc = j + d[1];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1'){
                            if(ds.Union(index(i,j),index(nr,nc)))ans--;
                        } 
                    }
                }
            }
        }
        return ans;
    }
};
