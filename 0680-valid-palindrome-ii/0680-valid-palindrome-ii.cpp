class Solution {
public:
    bool validPalindrome(string s) {
        int i{0};
        int j = s.length()-1;
        int count{0};
        while (i < j) {
            if (s[i] != s[j]) {
                if (count == 1)
                    return false;
                if (isPalindrome(s, i+1, j)) {
                    count++;
                    break;
                } 
                else if (isPalindrome(s, i, j-1)) {
                    count++;
                    break;
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