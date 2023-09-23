class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;
        int fsize = flowerbed.size();

        while (i < fsize) {
            if (flowerbed[i] == 1) {
                
                if (i > 0) flowerbed[i-1] = -1;
                if (i < fsize - 1) flowerbed[i+1] = -1;
            }
            i++;
        }

        i = 0;
        while (i < fsize) {
            if (flowerbed[i] == 0) {
                n--;
                
                if (i > 0) flowerbed[i-1] = -1;
                if (i < fsize - 1) flowerbed[i+1] = -1;
                i += 2; 
            } else {
                i++;
            }
        }

        return (n <= 0);
    }
};
