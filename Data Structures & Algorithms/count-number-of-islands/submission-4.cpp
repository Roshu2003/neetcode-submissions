class Solution {
public:
    vector<vector<char>> v;
    int dfs(int i,int j){
        char ch = v[i][j];
        int n = v.size();
        int m = v[0].size();
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        int ans = 1;
        v[i][j] = '0';
        for(int k = 0; k < 4; k++){
            int nr = i + dx[k];
            int nc = j + dy[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && v[nr][nc] == '1'){
                ans += dfs(nr,nc);
            }
        }
        // v[i][j] = ch;
        return ans;
    }
    int numIslands(vector<vector<char>>& grid) {
        v = grid;
        int ans = 0;
        int n = v.size();
        int m = v[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == '1'){
                    dfs(i,j);
                    ans++;
                }
            }
        }   
        return ans;
    }
};
