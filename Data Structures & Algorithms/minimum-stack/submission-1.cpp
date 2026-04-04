class MinStack {
private:
    stack<long> st;
    long minVal;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()) 
        {
            st.push(0);
            minVal = val;
        }
        else
        {
            long diff = (long)val - minVal;
            st.push(diff);
            if(diff < 0) minVal = val;
        }
    }

    void pop() {
        if (st.top() < 0)
        {
            minVal = minVal - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top()<0) return minVal;
        else return minVal + st.top();
    }
    
    int getMin() {
        return minVal;
    }
};
