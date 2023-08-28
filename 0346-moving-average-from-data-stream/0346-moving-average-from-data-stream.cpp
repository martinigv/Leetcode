class MovingAverage {
public:
    deque<int> dq;
    int s;
    MovingAverage(int size) {
        s = size;
    }
    
    double next(int val) {
        int ans = 0;
        if (dq.size() == s) {
            dq.pop_front();
        }
        dq.push_back(val);
        for (const int& value : dq) {
            ans += value;
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