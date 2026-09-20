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
        dp.assign(n,vector<int>(amount + 1,-1));
        int ans = solve(0,amount);
        return ans == 1e9 ? -1 : ans;
    }
};
