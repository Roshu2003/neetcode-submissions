class Solution {
public:
    void dfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> & vis){
        vis[i][j] = 1;
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        for(int k = 0 ; k < 4; k++){
            int nr = i + dx[k];
            int nc = j + dy[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == '1'){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n ,vector<int> (m,0));
        int cnt = 0;
        for(int i = 0 ;i < n; i++){
            for(int j = 0; j < m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
