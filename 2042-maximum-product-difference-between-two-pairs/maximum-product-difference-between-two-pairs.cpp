class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maxi1 = INT_MIN, maxi2 = INT_MIN;
        int mini1 = INT_MAX, mini2 = INT_MAX;

        for (int x : nums) {

            if (x >= maxi1) {
                maxi2 = maxi1;
                maxi1 = x;
            }
            else if (x > maxi2) {
                maxi2 = x;
            }

            if (x <= mini1) {
                mini2 = mini1;
                mini1 = x;
            }
            else if (x < mini2) {
                mini2 = x;
            }
        }

        return maxi1 * maxi2 - mini1 * mini2;
    }
};