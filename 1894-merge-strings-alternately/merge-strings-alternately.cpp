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
        // // Baaki ke characters jo bache, unhe add karna hai (agar kuch bacha ho)
        // word1[n-1:word1.size()] ye python ka string slicing ka syntax hh 
        result.append(word1.substr(n));
        result.append(word2.substr(n));
        return result; 
    }
};