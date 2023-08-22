class BrowserHistory {
public:
    stack<string> backst {};
    stack<string> forst {};
    BrowserHistory(string homepage) {
        backst.push(homepage);
    }
    
    void visit(string url) {
        backst.push(url);
        while(!forst.empty()) { //in problem step(visit): clear all the forward history
            forst.pop();
        }
        cout << url << endl;
    }
    
    string back(int steps) {
        while (steps > 0 && backst.size() > 1) {
            forst.push(backst.top());
            backst.pop();
            steps--;
        }
        return backst.top();
    }
    
    string forward(int steps) {
        while (steps > 0 && !forst.empty()) {
            backst.push(forst.top());
            forst.pop();
            steps--;
        }
        return backst.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */