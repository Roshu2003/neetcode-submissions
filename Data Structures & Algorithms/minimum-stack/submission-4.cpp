class MinStack {
public:
    stack<int> mn,st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        val = min(val,(mn.empty() ? val : mn.top()));
        mn.push(val);
    }
    
    void pop() {
        st.pop();
        mn.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};
