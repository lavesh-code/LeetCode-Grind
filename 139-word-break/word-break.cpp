class Solution {
public:
    bool wordBreakUtil(string s, unordered_set<string>& wordSet, int start, vector<int>& memo) {
        if (start == s.size()) return true;
        if (memo[start] != -1) return memo[start];

        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);
            if (wordSet.count(word) && wordBreakUtil(s, wordSet, end, memo)) {
                return memo[start] = true;
            }
        }

        return memo[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1);
        return wordBreakUtil(s, wordSet, 0, memo);
    }
};