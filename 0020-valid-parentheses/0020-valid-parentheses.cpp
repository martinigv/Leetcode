class Solution {
public:
    bool isValid(string s) {
        if (s.length() < 2)
            return false;
        stack<int> st;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else {
                if (st.empty())
                    return false;
                else if (st.top() + 1 == s[i] || st.top() + 2 == s[i]) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }
        if (st.empty())
            return true;
        return false;
    }
};