class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0;
        int j = 0;
        while (i < pushed.size() && j < popped.size()) {
            while (st.empty() || (i < pushed.size() &&st.top() != popped[j])) {
                st.push(pushed[i]);
                i++;
            }

            while (!st.empty() && j < popped.size() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        return st.empty();

    }
};