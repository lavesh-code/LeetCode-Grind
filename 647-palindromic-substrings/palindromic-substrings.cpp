class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        auto expandFromMiddle = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        };

        // Loop through each character (and in-between for even-length palindromes)
        for (int i = 0; i < n; i++) {
            // Odd-length palindromes (single character center)
            expandFromMiddle(i, i);
            // Even-length palindromes (two-character center)
            expandFromMiddle(i, i + 1);
        }
        return count;
    }
};