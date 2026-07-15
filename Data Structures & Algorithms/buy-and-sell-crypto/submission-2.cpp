class Solution {
public:
    int n;
    vector<int> nums;
int solve(int i, int buy){

    if(i >= n)
        return 0;

    int take = 0;
    int nottake = 0;

    if(buy){

        // Buy
        take = -nums[i] + solve(i+1,0);

        // Skip buying
        nottake = solve(i+1,1);

    }
    else{

        // Sell
        take = nums[i] + solve(i+1,1);

        // Skip selling
        nottake = solve(i+1,0);
    }

    return max(take,nottake);
}
    int maxProfit(vector<int>& v) {
        int ans = 0;
        nums = v;
        n = nums.size();
        int mxP = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            ans = max(ans,mxP - nums[i]);
            mxP = max(mxP,nums[i]);
        }
        return ans;
    }
};
//take = -7;
