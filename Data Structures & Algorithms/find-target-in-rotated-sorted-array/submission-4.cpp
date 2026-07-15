class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int l = 0;
        int r = nums.size() - 1;
        // int ans = -
        while(l <= r){
            int mid = ( l + r ) / 2; 
            if(nums[mid] == tar)return mid;
            else if(nums[mid] >= nums[l]){
                if(nums[l] <= tar && tar < nums[mid])r = mid - 1;
                else l = mid + 1;
            }
            else{
                if(nums[r] >= tar && tar > nums[mid])l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};

/*5 1 3
l = 0, r = 2;
m = (0 + 2) / 2 = 1;


*/
