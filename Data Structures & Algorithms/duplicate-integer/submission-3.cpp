class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for(auto it : nums){
            if(mp.count(it))return true;
            mp[it]++;
        }
        return false;
    }
};