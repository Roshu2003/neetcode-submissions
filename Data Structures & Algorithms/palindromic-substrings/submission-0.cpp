class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));
        for(int l = 1; l <= n; l++){
            for(int i = 0; i + l <= n; i++){
                int j = i + l - 1;
                if(i == j){
                    dp[i][j] = 1;
                }
                else if(i + 1 == j){
                    dp[i][j] = (s[i] == s[j]);
                }
                else{
                    dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(dp[i][j])ans++;
            }
        }
        return ans;
    }
};
