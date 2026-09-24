class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        map<char,int> mp;
        for(auto it : t)mp[it]++;
        int st = 0;
        int l = -1;
        int ans = 1e9;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(mp[s[i]] > 0)cnt++;
            mp[s[i]]--;//we can not use more than one time

            while(cnt == m){
                if(i - st + 1 < ans){
                    ans = i - st + 1;
                    l = st;
                }
                mp[s[st]]++;
                if(mp[s[st]] > 0)cnt--;
                st++;
            }
        }
        return ans == 1e9 ? "" : s.substr(l, ans);
    }
};
