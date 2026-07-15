class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty())return false;
                if((s[st.top()] == '(' && s[i] == ')') || (s[st.top()] == '[' && s[i] == ']') || (s[st.top()] == '{' && s[i] == '}'))st.pop();
                else return false;
            }else{
                st.push(i);
            }
        }
        return st.empty();
    }
};
