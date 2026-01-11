class MyQueue {
    private: 
    stack<int> st;
    stack<int> sparsest;
public:
    MyQueue() {}
    
    void push(int x) {
        while(!st.empty()){
            sparsest.push(st.top());
            st.pop();
        }
        st.push(x);
        while(!sparsest.empty()){
            st.push(sparsest.top());
            sparsest.pop();
        }
    }
    
    int pop() {
       int front = st.top();
       st.pop();
       return front;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */