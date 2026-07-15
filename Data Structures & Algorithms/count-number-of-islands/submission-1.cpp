class DSU{
    vector<int> parent,size;
    public:
    DSU(int n){
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0;i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
        int find(int node){
            if(node == parent[node])return node;
            return parent[node] = find(parent[node]);
        }
        bool Union(int u,int v){
            int pu = find(u);
            int pv = find(v);
            if(pv == pu)return false;
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
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        for(int i =0 ; i < n ;i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    for(int k =0 ; k < 4 ;k++){
                        int nr = i + dx[k];
                        int nc = j + dy[k];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == '1'){
                            if(ds.Union(i * m + j,nr * m + nc))ans--;
                        }
                    }
                }
            }

        }
        return ans;
    }
};
