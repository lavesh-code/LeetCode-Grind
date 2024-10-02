class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        vector<int> arr;
        
        // Adding extra 0s at the beginning and end of the array
        arr.push_back(0);
        for(int i = 0; i < s; i++) {
            arr.push_back(flowerbed[i]);
        }
        arr.push_back(0);
        
        // Loop to try and plant flowers
        for(int i = 1; i <= s; i++) {
            if(arr[i-1] == 0 && arr[i] == 0 && arr[i+1] == 0) {
                arr[i] = 1;  // Plant flower
                n--;         // Decrease number of flowers to be planted
                
                // If n becomes 0 or negative, we can return true
                if(n <= 0) {
                    return true;
                }

                // Move two positions forward to avoid adjacent planting
                i++;
            }
        }

        // If n is 0 or less, we were able to plant all the required flowers
        return n <= 0;
    }
};