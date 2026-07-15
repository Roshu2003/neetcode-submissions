class Solution {
public:
    string minWindow(string s, string t) {
        int len = INT_MAX;
        int start = -1;
        int cnt = 0;
        int m = t.size();
        map<char,int> mp;
        for(auto it : t)mp[it]++;
        int st = 0;
        int n = s.size();
        for(int i = 0; i < n ;i++){
            if(mp[s[i]] > 0)cnt++;
            mp[s[i]]--;

            while(cnt == m){
                if(i - st + 1 < len){
                    len = i - st + 1;
                    start = st;
                }
                mp[s[st]]++;
                if(mp[s[st]] > 0)cnt--;
                st++;
            }
        }
        return len ==INT_MAX ? "":s.substr(start,len);
    }
};
