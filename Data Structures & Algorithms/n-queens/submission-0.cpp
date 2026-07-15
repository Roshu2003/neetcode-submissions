class Solution {
public:
    vector<vector<string>> ans;
    bool isSafe(int i, int j,vector<string> &ds){
        //check vertical
        for(int r = 0; r < i; r++){
            if(ds[r][j] == 'Q')return false;
        }
        //check left diagonal
        int r = i - 1;
        int c = j - 1;
        while(r >= 0 && c >= 0){
            if(ds[r][c] == 'Q')return false;
            r--;
            c--;
        }
        //check right diagonal
        r = i - 1;
        c = j + 1;
        while(r >= 0 && c < ds[0].size()){
            if(ds[r][c] == 'Q')return false;
            r--;
            c++;
        }
        return true;
    }
    void solve(int r,vector<string> &ds){
        if(r == ds.size()){
            ans.push_back(ds);
            return;
        }
        for(int c = 0; c < ds.size(); c++){
            if(isSafe(r,c,ds)){
                ds[r][c] = 'Q';
                solve(r + 1,ds);
                ds[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ds(n,string(n,'.'));
        solve(0,ds);
        return ans;
    }
};
