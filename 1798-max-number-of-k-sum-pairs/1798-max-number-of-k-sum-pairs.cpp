class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        /*int count = 0;
        if (nums.size() < 2)
            return count;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0)
                continue; 

            int n = k - nums[i];
            for (int j = nums.size()-1; j > i; j--) {
                if (nums[j] < 0) 
                    continue;

                if (nums[j] == n) {
                    count++;
                    nums[i] = -1;
                    nums[j] = -1; 
                    break;  
                }
            }
        }
        return count;
        */
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
};