class Solution {
public:
    vector<int> dp;
    int solve(int i, vector<int> &nums){
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i] != -1)return dp[i];
        int ans = max(solve(i + 1,nums),nums[i] + solve(i + 2,nums));
        return dp[i] = ans;
    }
    int getAns(vector<int> & nums){
        int n = nums.size();
        dp.assign(n,-1);
        return solve(0,nums);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        vector<int> a;
        for(int i = 1; i < nums.size(); i++)a.push_back(nums[i]);
        nums.pop_back();
        return max(getAns(nums),getAns(a));
    }
};
