class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int l = 0;
        int r = 0;
        while(r < n - 1){
            int  f = 0;
            for(int i = l; i <= r; i++){
                f = max(f,nums[i] + i);
            }
            l = r + 1;
            r = f;
            ans++;
        }
        return ans;
    }
};
