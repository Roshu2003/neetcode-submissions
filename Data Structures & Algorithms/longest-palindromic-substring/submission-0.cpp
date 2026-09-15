class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n + 1,vector<int>(n + 1,0));
        for(int l = 1; l <= n; l++){
            for(int i =0 ; i + l <= n; i++){
                int j = i + l - 1;
                if(i == j)dp[i][j] = 1;
                else if(i  + 1 == j)dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (dp[i + 1][j - 1] && s[i] == s[j]);
            }
        }
        int st = 0;
        int len = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j]){
                    if(len < j - i + 1){
                        len = j - i + 1;
                        st = i;
                    }
                }
            }
        }
        return s.substr(st,len);
    }
};
