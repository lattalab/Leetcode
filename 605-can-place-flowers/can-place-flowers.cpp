class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        // corner
        if (size == 1) {
            return flowerbed[0] == 0 ? true 
                   : (n >= 1) ? false : true;
        }

        for (int i=0; i<size; i++) {
            if (i==0 && flowerbed[i] == 0 && flowerbed[i+1] != 1) {
                // arr[0] can flowered
                flowerbed[i] = 1;
                n--;
            }
            else if (i > 0 && i < size-1 && flowerbed[i] == 0 && flowerbed[i-1] != 1 && flowerbed[i+1] != 1) {
                // middle part can placed
                flowerbed[i] = 1;
                n--;
            }
            else if (i == size-1 && flowerbed[i] == 0 && flowerbed[i-1] != 1) {
                // arr[size-1] can placed
                flowerbed[i] = 1;
                n--;
            }
            // early stop
            if (n <= 0) return true;
        }
        
        return false;
    }
};