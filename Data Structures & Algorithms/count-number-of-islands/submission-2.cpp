class Solution {
public:
    vector<vector<int>> vis;
    vector<vector<char>> v;
    void dfs(int i,int j){
        vis[i][j] = 1;
        int n = v.size();
        int m = v[0].size();
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int d =0 ;d < 4; d++){
            int nr = i + dx[d];
            int nc = j + dy[d];
            if(nr >= 0 && nc >= 0 && nr < n && nc < m &&!vis[nr][nc] && v[nr][nc] == '1'){
                dfs(nr,nc);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        v = grid;
        int n = v.size();
        int m = v[0].size();
        vis.assign(n,vector<int>(m,0));
        int ans =0 ;
        for(int i =0 ; i < n ;i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == '1' && !vis[i][j]){
                    dfs(i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
