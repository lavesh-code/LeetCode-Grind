class Solution {
public:
    bool isValid(string& ans, int i){
        return (i<1 || ans[i]!=ans[i-1]) && (i<2 || ans[i]!=ans[i-2]);
    }

    string smallestBeautifulString(string s, int k) {
        string ans = s;
        for(int i=ans.length()-1; i>=0; i--){
            ans[i]++;

            while(!isValid(ans, i)) ans[i]++;

            if(ans[i] < 'a'+k){
                for(int j=i+1; j<ans.length(); j++){
                    ans[j] = 'a';
                    while(!isValid(ans, j))  ans[j]++;
                }

                return ans;
            }
        }

        return "";
    }
};