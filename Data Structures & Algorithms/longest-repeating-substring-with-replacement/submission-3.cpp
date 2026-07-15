class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();
        unordered_map<int,int>mp;
        int st = 0;
        int mx = -1;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
            mx  = max(mx,mp[s[i]]);
            while((i - st + 1) - mx > k){
                if(--mp[s[st]] == 0){
                    mp.erase(mp[s[st]]);
                }
                st++;
            }
            ans = max(ans,i - st + 1);
        }
        return ans;
    }
};
