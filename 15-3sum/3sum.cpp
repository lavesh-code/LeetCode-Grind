class Solution {
public:
    vector<vector<int>> threeSumUtil(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end()); // n logn
        
        for (int i = 0; i < n; i++) {
            // skip the duplicates:
            if (i != 0 && arr[i] == arr[i - 1]) continue;
            
            // pointer i --> index i
            // moving 2 pointers:
            int j = i + 1;
            int k = n - 1;
            while (j < k) { // n^2 
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < target) {
                    j++;
                }
                else if (sum > target) {
                    k--;
                }
                else {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    //skip the duplicates:
                    while (j < k && arr[j] == arr[j - 1]) j++;
                    while (j < k && arr[k] == arr[k + 1]) k--;
                }
            }
        }
        return ans;
    }


    vector<vector<int>> threeSum(vector<int>& arr){
        int target = 0;
        vector<vector<int>> ans = threeSumUtil(arr,target);
        return ans; 
    }
};

