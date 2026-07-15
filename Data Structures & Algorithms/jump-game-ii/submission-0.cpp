class Solution {
public:
int dfs(int i,vector<int> & nums){
    int n = nums.size();
    if(i == n - 1)return 0;
    if(nums[i] == 0)return 1e6;
    int ans = 1e9;
    int mx = min(i + nums[i],n - 1);
    for(int j = i + 1; j <= mx; j++){
        ans = min(ans, 1 + dfs(j,nums));
    }
    return ans;
}
    int jump(vector<int>& nums) {
        return dfs(0,nums);
    }
};
