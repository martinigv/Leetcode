/* class Solution {
public:
    vector<vector<int>> transBinary(vector<vector<int>>& prev,int n,int max) {
        // 0 1 01 11 001
        if (n > max)
            return prev;
        int end = prev[n-1].size()-1;
        vector<int> curr;
        curr = prev[n-1];
        curr[0]++;
        for (int i = 0; i <= end; i++) {
            if (curr[i] == 2) {
                if (i == end) {
                    curr[i] = 0;
                    curr.push_back(1);
                    continue;
                }
                curr[i] = 0;
                curr[i+1]++;
            }
        }
        for (auto v : curr) {
            cout << v;
        }
        cout << endl;
        prev.push_back(curr);
        return transBinary(prev, n+1, max);
    }
    vector<int> countOne(vector<vector<int>> v) {
        vector<int> res(v.size());
        for (int i = 0; i < v.size(); i++) {
            int count = 0;
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j] == 1)
                    count++;
            }
            res[i] = count;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<vector<int>> v;
        vector<vector<int>> first = {{0}};
        vector<int> ans;
        v = transBinary(first, 1, n);
        ans = countOne(v);
        return ans;
    }
}; */

// circulate bits directly
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
        for (int i = 1; i <= num; ++i)
            ret[i] = ret[i&(i-1)] + 1;
        return ret;
    }
};