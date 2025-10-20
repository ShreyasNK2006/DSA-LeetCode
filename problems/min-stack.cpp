# Min Stack
Solved on 2025-10-19

class MinStack {
    private: 
    stack<int> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int> copy = st;
        int mine = copy.top();
        copy.top();
        while(!copy.empty())
        {
            mine = min(mine,copy.top());
            copy.pop();
        }
        return mine;
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