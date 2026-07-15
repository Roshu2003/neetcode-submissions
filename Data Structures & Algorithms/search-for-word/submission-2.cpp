class Solution {
public:
    vector<vector<char>> grid;
    string s;
    vector<vector<int>>vis;
    int n,m;
    bool solve(int i,int j,int k){
        if(k >= s.size())return true;
        if(i >= n || j >= m)return false;

        bool ans = false;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int id = 0; id < 4; id++){
            int nr = i + dx[id];
            int nc = j + dy[id];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] == s[k]){
                vis[nr][nc] = 1;
                if(solve(nr,nc,k + 1))return true;
                vis[nr][nc] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& v, string ss) {
        n = v.size();
        m = v[0].size();
        grid = v;
        s = ss;
        int k = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(v[i][j] == ss[0]){
                    vis.assign(n,vector<int>(m,0));
                    vis[i][j] = 1;
                    if(solve(i,j,1) == true)return true;
                }
            }
        }
        return false;
    }
};
