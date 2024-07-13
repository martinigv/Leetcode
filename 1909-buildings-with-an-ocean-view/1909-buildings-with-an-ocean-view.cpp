class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        stack<int> st;
        int curr = 0;

        for (;curr < heights.size(); curr++) {
            while(!st.empty() && heights[curr] >= heights[st.top()]) {
                st.pop();
            }
            st.push(curr);
        }
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};