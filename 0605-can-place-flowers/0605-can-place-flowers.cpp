class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        /* int i = 0;
        int fsize = flowerbed.size();

        while (i < fsize) {
            if (flowerbed[i] == 1) {
                
                if (i > 0) 
                    flowerbed[i-1] = -1;
                if (i < fsize - 1) 
                    flowerbed[i+1] = -1;
            }
            i += 2;
        }

        i = 0;
        while (i < fsize) {
            if (flowerbed[i] == 0) {
                n--;
                
                if (i > 0) 
                    flowerbed[i-1] = -1;
                if (i < fsize - 1) 
                    flowerbed[i+1] = -1;
                i += 2; 
            } 
            else {
                i++;
            }
        }

        return (n <= 0);
        */
        int count = 0;
        for (int i = 0; i < flowerbed.size() && count < n; i++) {
            if (flowerbed[i] == 0) {
                // Get next and prev flower bed slot values. If i lies at the ends, the next and prev are considered as 0.
                int next = (i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1];
                int prev = (i == 0) ? 0 : flowerbed[i - 1];
                if (next == 0 && prev == 0) {
                    flowerbed[i] = 1;
                    count++;
                }
            }
        }

        return count == n;
    }
}; 
