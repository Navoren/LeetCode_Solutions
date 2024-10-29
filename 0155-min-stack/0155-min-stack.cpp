class MinStack {
public:

stack <long long> st;
long long mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(long long val) {;
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val < mini){
                long long newMin = 2*val*1LL-mini;
                st.push(newMin);
                mini = val;
            }
            else st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        long long x = st.top();
        st.pop();
        if(x < mini) mini = 2*mini - x;
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top() > mini) return st.top();
        else{
            return mini;
        }
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */