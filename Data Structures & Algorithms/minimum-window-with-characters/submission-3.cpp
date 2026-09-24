class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int len = INT_MAX;
        int st = -1;
        int req = 0;
        int form  = 0;
        map<char,int> mp,window;
        for(auto it : t)mp[it]++;
        for(auto it : mp){
            if(it.second > 0)req++;
        }
        int l = 0;
        for(int i  = 0; i < n; i++){
            window[s[i]]++;
            if(mp[s[i]] > 0 && mp[s[i]] == window[s[i]])form++;

            while(req == form){
                if(i - l + 1 < len){
                    len = i - l + 1;
                    st = l;
                }
                window[s[l]]--;
                if(mp[s[l]] > 0 && window[s[l]] < mp[s[l]])form--;
                l++;
            }
        }
        return (len == INT_MAX) ? "" : s.substr(st,len);
    }
};
