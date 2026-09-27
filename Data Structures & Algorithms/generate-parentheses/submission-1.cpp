class Solution {
public:
    vector<string> ans;
    void solve(int o,int c,int n,string s){
        if(o == c && o == n){
            ans.push_back(s);
            return;
        }
        if(o < n){
            s += '(';
            solve(o + 1,c,n,s);
            s.pop_back();
        }
        if(c < o){
            s += ')';
            solve(o,c + 1,n,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(0,0,n,"");
        return ans;
    }
};
