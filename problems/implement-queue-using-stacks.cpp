# Implement Queue using Stacks
Solved on 2025-10-18

class MyQueue {
    private:
    stack<int> st;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        reverse(st);
        int top =st.top();
        st.pop();
        reverse(st);
        return top;
    }
    
    int peek() {
        reverse(st);
        int top =st.top();
        reverse(st);
        return top;
    }
    
    bool empty() {
        return st.empty();
    }
    void reverse(stack<int> &temp1)
    {
        stack<int> temp2;
        while(!temp1.empty())
        {
            temp2.push(temp1.top());
            temp1.pop();
        }
        temp1 = temp2;
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