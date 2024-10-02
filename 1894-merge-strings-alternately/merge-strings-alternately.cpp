class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = ""; 
        int n = min(word1.size(), word2.size());
        // iss loop ke baad dono me se jo chhoti string hogi vo khatam ho jayegi
        for(int i=0; i< n; i++){
            result.push_back(word1[i]);
            result.push_back(word2[i]);
        }
        result.append(word1.substr(n));
        result.append(word2.substr(n));
        return result; 
    }
};