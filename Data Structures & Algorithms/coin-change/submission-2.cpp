class Solution {
public:
    vector<int> nums;
    int n;
    // int k;
    vector<vector<int>> dp;
    int solve(int i,int k){
        if(k == 0)return 0;
        if(i >= n)return 1e9;
        if(dp[i][k] != -1)return dp[i][k];
        int take = 1e9;
        int nottake = solve(i + 1,k);
        if(nums[i] <= k){
            take = 1 + solve(i, k - nums[i]);
        }
        return dp[i][k] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        nums = coins;
        n = nums.size();
        dp.assign(n + 1,vector<int>(amount + 1,1e9));
        for(int i = 0; i <= n; i++)dp[i][0] = 0;
        for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= amount; k++) {

            dp[i][k] = dp[i - 1][k];

            if (k >= coins[i - 1]) {
                dp[i][k] = min(dp[i][k], 1 + dp[i][k - coins[i - 1]]);
            }
            }
          }
        // int ans = solve(0,amount);
       return dp[n][amount] == 1e9 ? -1 : dp[n][amount];
    }
};
