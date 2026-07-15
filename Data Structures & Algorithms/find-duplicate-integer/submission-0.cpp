class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = 0;
        int f = 0;
        while(1){
            s = nums[s];
            f = nums[nums[f]];
            if(s == f)break;
        }
        int s2 = 0;
        while(true){
            s = nums[s];
            s2 = nums[s2];
            if(s == s2)return s;
        }
        return 0;
    }
};

// 2 * a +  (y - a) = x
// a + b = y; 
//a = x - y;
