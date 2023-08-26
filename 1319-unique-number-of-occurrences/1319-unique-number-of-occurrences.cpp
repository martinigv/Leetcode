class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            auto it = mp.find(arr[i]);
            if (it == mp.end()) {
                mp.emplace(arr[i], 1);
            }
            else {
                it->second++;
            }
        }
        unordered_set<int> s;
        for (auto& k : mp) {
            if (s.count(k.second) > 0) {
                return false;
            }
            else {
                s.insert(k.second);
            }
        }
        return true;
    }
};