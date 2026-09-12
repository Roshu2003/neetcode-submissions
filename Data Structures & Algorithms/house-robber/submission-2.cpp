class Solution {
public:
    vector<int> nums;
    // int dp[1001];
    vector<int> dp;
    int n;
    int solve(int i){
        if(i >= n)return 0;
        if(dp[i] != -1)return dp[i];
        int skip = 0 + solve(i + 1);
        int take = nums[i] + solve(i + 2);
        return dp[i] = max(take,skip);
    }
    int rob(vector<int>& num) {
        nums = num;
        n = nums.size();
        dp.assign(n,-1);
        // memset(dp,-1,sizeof(dp));
        return solve(0);
    }
};
