class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        
        int temp2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                temp2 = matrix[i][j];
                matrix[i][j] = matrix[i][n - j - 1];
                matrix[i][n - j - 1] = temp2;
            }
        }
    }
};