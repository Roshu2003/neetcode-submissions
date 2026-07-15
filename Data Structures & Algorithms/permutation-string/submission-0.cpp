class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len = s1.size();
        sort(s1.begin(),s1.end());
        int len2 = s2.size();
        for(int i = 0; i < len2; i++){
            string t = "";
            for(int j = i; j < len + i; j++){
                t += s2[j];
            }
            sort(t.begin(),t.end());
            if(t == s1)return true;
        }
        return false;
    }
};
