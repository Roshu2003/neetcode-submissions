class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int st =0 ;
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            while(mp[s[i]] > 1){
                if(--mp[s[st]] == 0)mp.erase(s[st]);
                st++;
            }
            ans = max(ans,i - st + 1);
        }
        return ans;
    }
};
