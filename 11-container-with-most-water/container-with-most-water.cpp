class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int max_area = 0;

        while(l < r){
            int curr = (r-l) * min(height[l], height[r]);
            cout << curr << endl; 
            max_area = max(max_area, curr);
            if(height[l] < height[r]) l++;
            else{
                r--;
            }  
        }

        return max_area; 
    }
};