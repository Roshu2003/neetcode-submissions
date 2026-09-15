class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = -1;
        int st = 0;
        for(int i = 0; i < n; i++){
            //odd length
            int l = i;
            int r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > len){
                    len = r - l + 1;
                    st = l;
                }
                l--;
                r++;
            }

            //even length
            l = i;
            r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 > len){
                    len = r - l + 1;
                    st = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(st,len);
    }
};
