class Solution {
public:
    bool solve(int i,vector<int> &nums){
        // if(i >)
        if(i == nums.size() - 1)return true;
        bool take = false;
        // bool nottake = solve(i + 1,nums);
        int maxJump = min((int)nums.size() - 1,i + nums[i]);
        for(int j = i + 1; j <= maxJump; j++){
            take |= solve(j,nums);
            if(take == true)return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        return solve(0,nums);
    }
};
