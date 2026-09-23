class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n,0);
        right[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            right[i] = max(right[i + 1],nums[i]);
        }
        int left = nums[0];
        int ans = 0;
        for(int i = 1; i < n - 1; i++){
            ans += max(0,min(left,right[i + 1]) - nums[i]);
            left = max(left,nums[i]);
        }
        return ans;
    }
};
