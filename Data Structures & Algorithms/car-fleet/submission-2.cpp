class Solution {
public:
    int carFleet(int tar, vector<int>& p, vector<int>& sp) {
        vector<pair<int,int>> v;
        for(int i  = 0 ;i < p.size(); i++){
            v.push_back({p[i],sp[i]});
        }
        sort(v.rbegin(),v.rend());
        vector<double> st;
        for(auto it : v){
            st.push_back((double)(tar - it.first) / it.second);
            if(st.size() >= 2 && st.back() <= st[st.size() - 2])st.pop_back();
        }
        return st.size();
    }
};
