class Solution {
public:
    vector<string> ans;
    void dfs(int open,int close,int n,string &s){
        if(open == close && open == n){
            ans.push_back(s);
            return
            ;
        }
        if(open < n){
            s += '(';
            dfs(open + 1,close,n,s);
            s.pop_back();
        }
        if(close < open){
            s += ')';
            dfs(open, close + 1,n,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        dfs(0,0,n,s);
        return ans;
    }
};
