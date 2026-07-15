class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mp;
        for(auto it:s1){
            mp[it]++;
        }
        int need = mp.size();
        for(int i = 0;i < s2.size(); i++){
            map<char,int> count;
            int cur = 0;
            for(int j = i; j < s2.size(); j++){
                char c = s2[j];
                count[c]++;
                if(mp[c] < count[c])break;
                if(mp[c] == count[c]){
                    cur++;
                }
                if(cur == need){
                    return true;
                }
            }
        }
        return false;
    }
};
