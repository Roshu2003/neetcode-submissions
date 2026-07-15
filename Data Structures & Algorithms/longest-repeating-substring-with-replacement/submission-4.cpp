class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        set<char> st(s.begin(),s.end());
        for(auto c : st){
            int count = 0;
            int l = 0;
            for(int r = 0; r < n; r++){
                if(s[r] == c){
                    count++;
                }
                while((r - l + 1) - count > k){
                    if(s[l] == c){
                        count--;
                    }
                    l++;
                }
                ans = max(r - l + 1,ans);
            }
        }
        return ans;
    }
};
