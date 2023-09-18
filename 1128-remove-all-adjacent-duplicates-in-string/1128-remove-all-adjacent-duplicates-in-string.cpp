class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans;
        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop();
                continue;
            }    
            st.push(c);
        }
        while(!st.empty()) {
            ans.insert(ans.begin(), st.top());
            st.pop();
        }
        return ans;
    }
};