/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& nums) {
        vector<pair<int,int>> v;
        for(auto it:nums){
            v.push_back({it.start,1});
            v.push_back({it.end,-1});
        }
        sort(v.begin(),v.end());
        int ans = 0;
        int cnt =0 ;
        for(auto it:v){
            cnt += it.second;
            ans =max(ans,cnt);
        }

return ans;    }
};
