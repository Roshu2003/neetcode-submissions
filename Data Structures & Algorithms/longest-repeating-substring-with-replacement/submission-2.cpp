class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            unordered_map<char,int> mp;
            int maxi = 0;
            for(int j = i; j < n; j++){
                mp[s[j]]++;
                maxi = max(maxi,mp[s[j]]);
                if((j - i + 1) - maxi <= k){
                    ans = max(ans,j - i + 1);
                }
            }
        }
        return ans;
    }
};
