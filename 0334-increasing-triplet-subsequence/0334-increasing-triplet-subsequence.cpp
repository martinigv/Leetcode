class Solution {
public:
    
    bool increasingTriplet(vector<int>& nums) {
        int f = nums[0];
        int s = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if (f >= nums[i]) {
                f = nums[i];
            }
            else if (s >= nums[i]) {
                s = nums[i];
            }
            else {
                return true;
            }
        }
        return false;
    }
};