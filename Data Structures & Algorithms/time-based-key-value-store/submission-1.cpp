class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto &it = mp[key];
        int l = 0;
        int r = it.size() - 1;
        string ans = "";
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(it[mid].first <= timestamp){
                ans = it[mid].second;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};
