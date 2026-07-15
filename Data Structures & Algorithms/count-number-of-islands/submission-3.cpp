class DSU{
    public:
    vector<int> p,sz;
    DSU(int n){
        p.resize(n + 1);
        sz.resize(n + 1);
        for(int i = 0; i <= n; i++){
            p[i] = i;
            sz[i] = 1;
        }
    }
    
    int find(int node){
        if(node != p[node]){
            p[node] = find(p[node]);
        }
        return p[node];
    }
    bool unionbysz(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)return false;
        if(sz[pu] >= sz[pv]){
            sz[pu] += sz[pv];
            p[pv] = pu;
        }
        else{
            sz[pv] += sz[pu];
            p[pu] = pv;
        }
        return true;
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        int ans = 0;
        DSU ds(n * m);
        int dx[] = {0,1,-1,0};
        int dy[] = {1,0,0,-1};
        
        auto idx = [&](int r,int c){
            return r * m + c;
        };

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(v[r][c] == '1'){
                    ans++;
                    for(int d = 0; d < 4; d++){
                        int nr = r + dx[d];
                        int nc = c + dy[d];
                        if(nr >= 0 && nr < n && nc >= 0 && nc < m && v[nr][nc] == '1'){
                            if(ds.unionbysz(idx(r,c),idx(nr,nc)))ans--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
