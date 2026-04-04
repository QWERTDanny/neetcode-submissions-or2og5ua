class MinStack {
private:
    stack<long> st;
    stack<long> minSt;
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        int minVal;
        if(minSt.empty() || val <= minSt.top()){
            minSt.push(val);
        }else
        {   
            minSt.push(minSt.top());
        }
    }

    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
