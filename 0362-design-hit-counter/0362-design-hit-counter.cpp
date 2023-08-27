class HitCounter {
public:
    deque<int> dq;
    stack<int> st;
    HitCounter() {
    }
    
    void hit(int timestamp) {
        dq.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        if (dq.empty())
            return 0;
        int hitcnt = 0;
        while (!dq.empty() && dq.front() <= (timestamp - 300)) {
            dq.pop_front();
        }
        while(!dq.empty() && dq.front() <= timestamp) {
            st.push(dq.front());
            dq.pop_front();
            hitcnt++;
        }
        while(!st.empty()) {
            dq.push_front(st.top());
            st.pop();
        }
        return hitcnt;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */