/*class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.count(nums[i]) != 0)
                mp[nums[i]]++;
            else
                mp.emplace(nums[i], 1);
        }
        for (auto& key : mp) {
            int n = k - key.first;
            while(mp.count(n) && mp[key.first] > 0 && mp[n] > 0) {
                if (key.first == n && mp[n] < 2) {
                    break;
                }
                ans++;
                key.second--;
                mp[n]--;
            }
        }
        return ans;
    }
};*/
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        // support variables
        int res = 0;
        unordered_map<int, int> m;
        // main loop
        for (int n: nums) {
            if (m[k - n] > 0) {
                m[k - n]--;
                res++;
            }
            else m[n]++;
        }
        return res;
    }
};