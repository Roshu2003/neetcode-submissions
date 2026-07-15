class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int mxP = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            ans = max(ans,mxP - nums[i]);
            mxP = max(mxP,nums[i]);
        }
        return ans;
    }
};
