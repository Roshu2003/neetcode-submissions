class KthLargest {
public:
    int k;
    // vector<int> v;
    multiset<int> st;
    KthLargest(int kk, vector<int>& nums) {
        // v = nums;
        for(auto it : nums)st.insert(it);
        k = kk;
    }
    
    int add(int val) {
        st.insert(val);
        int ans = 0;
        int x = k;
        for(auto it = st.rbegin(); it != st.rend() && x > 0; it++){
            ans = *it;
            x--;
        }
        return ans;
    }
};
