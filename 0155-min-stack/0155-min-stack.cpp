class MinStack {
public:
    vector<int> v{};
    vector<int> v4m{};

    MinStack() {
        
    }

    void push(int val) {

        v.push_back(val);
        if (v4m.empty()) {
            v4m.push_back(val);
        }
        else if (val <= v4m.back()) {
            v4m.push_back(val);
        }
    }

    void pop() {
        if (v4m.back() == v.back())
            v4m.pop_back();
        v.pop_back();
    }

    int top() {
        return v.back();
    }

    int getMin() {
        return v4m.back();
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