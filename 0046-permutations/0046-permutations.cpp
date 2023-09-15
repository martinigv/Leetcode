class Solution {
public:
    void Backtracking(vector<vector<int>>& result, vector<int>& nums, vector<int>& aPermutation, vector<bool>& used) {
        if (aPermutation.size() == nums.size()) {
            result.push_back(aPermutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                aPermutation.push_back(nums[i]);

                Backtracking(result, nums, aPermutation, used);
                used[i] = false;
                aPermutation.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> aPermutation;
        Backtracking(result, nums, aPermutation, used);
        return result;
    }
    
};