class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxLength = 0;

        // Helper function to expand around the center
        auto expandFromMiddle = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
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

        return s.substr(start, maxLength);
    }
};