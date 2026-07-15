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
        int goal = nums.size() - 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            if(i + nums[i] >= goal){
                goal = i;
            }
        }
        return goal == 0;
    }
};
