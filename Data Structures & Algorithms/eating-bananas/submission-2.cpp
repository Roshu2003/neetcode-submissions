class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int hour) {
        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        int ans = 0;
        function<bool(int)> check = [&](int k) -> bool{
            int sum = 0;
            for(auto it : nums){
                sum += it / k + (it % k != 0);
                if(sum > hour)return false;
            }
            return sum <= hour;
        };
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(check(mid)){
                ans = mid;
                h = mid - 1;
            }else l = mid + 1;
        }
        return ans;
    }
};
