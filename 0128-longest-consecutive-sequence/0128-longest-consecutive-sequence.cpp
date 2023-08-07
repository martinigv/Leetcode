class Solution {
public:
    int max(vector<int> &lengths) {
        int max = lengths[0];
        for (int i = 1; i < lengths.size(); i++) {
            if (max < lengths[i])
                max = lengths[i];
        }
        return max;
    }
    int longestConsecutive(vector<int>& nums) {
        // 정렬을 하고
        // 각 원소가 -1이 없으면 새로운 행으로 n-1이 마지막에 있으면 추가
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> mp;
        vector<int> lengths;
        int key = nums[0];

        mp[key] = vector<int>{nums[0]};

        for (int i = 1; i < nums.size(); i++) {
            
            if (nums[i] == nums[i - 1]) continue;

            if (nums[i] - 1 == mp[key].back()) {
                
                mp[key].push_back(nums[i]);
            } 
            else {
                lengths.push_back(mp[key].size());
                key = nums[i];
                mp[key] = vector<int>{nums[i]};
            }
        }

        lengths.push_back(mp[key].size());

        return max(lengths);
    }
};