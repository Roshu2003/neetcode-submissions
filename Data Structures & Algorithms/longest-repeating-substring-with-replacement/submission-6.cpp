class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int mx =0 ;
        int ans =0 ;
        int st = 0;
        for(int i =0 ; i < s.size(); i++){
            mp[s[i]]++;
            mx = max(mx,mp[s[i]]);
            while((i - st + 1) - mx > k){+
                mp[s[st]]--;
                st++;
            }
            ans = max(ans,i - st + 1);
        }
        return ans;
    }
};
