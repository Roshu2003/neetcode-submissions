class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = 0; i < n; i++)dp[i][i] = 1;
        for(int l = 2; l <= n; l++){
            for(int i = 0; i <= n - l; i++){//till the i not become negative 
                int j = i + l - 1;//right index
                if(l == 2){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
            }
        }
        vector<vector<string>> ans;
        vector<string> ds;
        function<void(int)> dfs = [&](int i)->void{
            if(i >= s.size()){
                ans.push_back(ds);
            }

            for(int j = i; j < n; j++){
                if(dp[i][j]){
                    ds.push_back(s.substr(i,j - i + 1));
                    dfs(j + 1);
                    ds.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};
