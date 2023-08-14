class Solution {
public:
    int maxArea(std::vector<int>& height)
    {
        int area = 0;
        int h = 0;
        int i = 0;
        int j = height.size() - 1;

        while (i < j) {
            h = min(height[i], height[j]);
            area = max(area, (j-i) * h);

            while(height[i] <= h && i < j) {
                i++;
            }
            while(height[j] <= h && i < j) {
                j--;
            }
        }
        return area;
    }
};