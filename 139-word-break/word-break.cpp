class Solution {
public:
    bool wordBreakUtil(string s, unordered_set<string>& wordSet, int start, vector<int>& dp) {
        if (start == s.size()) return true;
        if (dp[start] != -1) return dp[start];

        for (int len = 1; len <= s.size(); len++) {
          string word = s.substr(start, len);
          if (wordSet.count(word) && wordBreakUtil(s, wordSet, start + len, dp)) {
              return dp[start] = true;
            }
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return wordBreakUtil(s, wordSet, 0, dp);
    }

};