class Solution {
public:
    bool validPalindrome(string s) {
        int i{0};
        int j = s.length()-1;
        int count{0};
        while (i < j) {
            if (count > 1)
                return false;
            if (s[i] != s[j]) {
                count++;
                if (isPalindrome(s, i+1, j)) {
                    i++;
                    continue;
                } 
                else if (isPalindrome(s, i, j-1)) {
                    j--;
                    continue;
                } 
                else {
                    return false;
                }
            }
            i++;
            j--;
        }

        return true;
    }

    bool isPalindrome(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};