class MovingAverage {
public:
    deque<int> dq;
    int s;
    stack<int> st;
    MovingAverage(int size) {
        s = size;
    }
    
    double next(int val) {
        int ans = 0;
        if (dq.size() == s) {
            dq.pop_front();
        }
        dq.push_back(val);
        while(!dq.empty()) {
            st.push(dq.front());
            ans += dq.front();
            dq.pop_front();
        }
        while(!st.empty()) {
            dq.push_front(st.top());
            st.pop();
        }
        int size = dq.size();
        return ans * 1.0 / size;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */