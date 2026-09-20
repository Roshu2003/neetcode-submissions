class Solution {
public:
    string s;
    vector<int> dp;
    int solve(int i){ 
        if(i >= s.size()){
            return 1;
        }
        if(dp[i] != -1)return dp[i];
        int ways = 0;
        //single char
        if(s[i] != '0'){
            ways = solve(i + 1);// 
        }
        // two digit
        if(s[i] != '0' && i + 1 < s.size() &&  s.substr(i, 2) <= "26"){
            ways += solve(i + 2);
        }
        return dp[i] = ways;
    }
    int numDecodings(string s_) {
        s = s_;
        int n = s.size();
        dp.assign(n + 1, 0);
        if(s[0] == '0')return 0;
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            if(s[i - 1] != '0') dp[i] += dp[i - 1];
            if(s[i - 2] != '0' &&  s.substr(i - 2, 2) <= "26")dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};
