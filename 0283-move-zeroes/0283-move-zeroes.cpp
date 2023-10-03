class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 1;

        while (i < nums.size() && j < nums.size()) {
            if (nums[i] != 0) {
              i++;
              if(j <= i) j = i + 1;
              continue;
            }
            if (nums[j] == 0) {
              j++;
              continue;
            }
            swap(nums[i], nums[j]);
            i++;
            j++;
        }
    }
};