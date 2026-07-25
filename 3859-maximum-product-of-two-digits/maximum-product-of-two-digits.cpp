class Solution {
public:
    int maxProduct(int n) {
        int maxi1 = INT_MIN;
        int maxi2 = INT_MIN;
        while (n != 0) {
            int dit = n % 10;
            n = n / 10;

            if (dit > maxi1) {
                maxi2 = maxi1;
                maxi1 = dit;
            } else if (dit > maxi2) {
                maxi2 = dit;
            }
            
        }

        return maxi1 *maxi2;
    }
};