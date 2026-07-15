class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prod = 1;
        int zero = 0;
        for(int i = 0; i <  n; i++){
            if(nums[i] == 0){
                zero++;
            }else
            {
                prod *= nums[i];
            }
        }
        if(zero >  1){
            return vector<int> (n,0);
        }
        vector<int> ans(n);
        for(int i = 0 ;i < n; i++){
            if(zero > 0){
                ans[i] = (nums[i] == 0) ? prod : 0;
            }
            else{
                ans[i] = prod/nums[i];
            }
        }
        return ans;
    }
};
