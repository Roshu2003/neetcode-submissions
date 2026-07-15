class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        map<char,int> mp;
        int ans = 0;
        int st = 0;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            while(mp[s[i]] > 1){
                if(--mp[s[st]] == 0){
                    mp.erase(s[st]);
                }
                st++;
            }
            ans = max(ans,(int)mp.size());
        }
        return ans;
    }
};
