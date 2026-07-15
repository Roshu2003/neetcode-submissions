class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char,int> mp;
        int ans = 0;
        int st = 0;
        for(int i = 0; i < n; i++){
            if(mp.find(s[i]) != mp.end()){
                st = max(mp[s[i]] + 1,st);
            }
            mp[s[i]] = i;
            ans = max(ans,i - st + 1);
        }
        return ans;
    }
};
