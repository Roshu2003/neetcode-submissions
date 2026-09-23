class Solution {
public:
    vector<int> nums;
    int solve(int i,int isbuy){
        if(i >= nums.size())return 0;
        int take = 0;
        int nottake = 0;
        if(isbuy){
            take = -nums[i] + solve(i + 1,!isbuy);
            nottake = solve(i + 1,isbuy);
        }
        else{
            take = nums[i] + solve(i + 1,false);
            nottake = solve(i + 1,isbuy);
        }
        return max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        nums = prices;
        // return solve(0,1);
        int ans = 0;
        int mx = nums[0];
        for(int i = 1; i < nums.size(); i++){
            ans = max(ans,nums[i] - mx);
            mx = min(mx,nums[i]);
        }
        return ans;
    }
};
