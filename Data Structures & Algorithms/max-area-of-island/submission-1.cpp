class Solution {
public:
    vector<vector<int>> vis,v;
    int n,m;
    int dfs(int i,int j,int &cnt){
       if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == 1 || v[i][j] == 0)return 0;
        int ans = 1;
        vis[i][j] = 1;
        // cnt += v[i][j];
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int d = 0; d < 4; d++){
            int nr = i + dx[d];
            int nc = j + dy[d];
            ans += (dfs(nr,nc,cnt));
            // if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && v[nr][nc] == 1)dfs(nr,nc,cnt);
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        v = grid;
        n = v.size();
        m = v[0].size();
        int ans =0;
        vis.assign(n,vector<int>(m,0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j]){
                    int cnt = 0;
                    cnt = dfs(i,j,cnt);
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};
