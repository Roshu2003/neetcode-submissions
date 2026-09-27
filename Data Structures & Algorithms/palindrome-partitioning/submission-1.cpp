class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));
        for(int l = 1; l <= n; l++){
            for(int i = 0; i + l <= n; i++){
                int j = i + l - 1;
                if(i == j){
                    dp[i][j] = 1;
                }
                else if(i + 1 == j) dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
        }   
        vector<vector<string>> ans;
        vector<string> ds;
        function<void(int)> solve = [&](int i) -> void {
            if(i >= n){
                ans.push_back(ds);
                return;
            }
            for(int j = i; j < n; j++){
                if(dp[i][j] == 1){
                    ds.push_back(s.substr(i, j - i + 1));
                    solve(j + 1);
                    ds.pop_back();
                }
            }
        };
        solve(0);
        return ans;
    }
};
