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
        dp.assign(n, -1);
        return solve(0);
    }
};
