class Solution {
public:
    vector<int> nums;
    // int dp[1001];
    vector<int> dp;
    int solve(int i){
        if(i < 0)return 1e9;
        if(i <= 1)return nums[i];
        if(dp[i] != -1)return dp[i];
        int one = nums[i] + solve(i - 1);
        int two = nums[i] + solve(i - 2);
        return dp[i] = min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        nums = cost;
        int n = nums.size();
        dp.assign(n + 1,0);
        // return min(solve(n - 1),solve(n - 2));
        for(int i = 2; i <= n; i++){
            dp[i] = min(dp[i - 1] + nums[i - 1],dp[i - 2] + nums[i - 2]);
        }
        return dp[n];
    }
};
