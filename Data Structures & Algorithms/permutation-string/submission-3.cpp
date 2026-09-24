class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> a(26,0),b(26,0);
        for(auto it : s1)a[it - 'a']++;
        int k = s1.size();
        for(auto i = 0; i < s2.size() ; i++){
            b[s2[i] -'a']++;
            if(i >= s1.size())b[s2[i - k] - 'a']--;
            if(a == b)return true;
        }
        return false;
    }
};
