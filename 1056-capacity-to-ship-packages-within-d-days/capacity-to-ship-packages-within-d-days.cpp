class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);
        while (left < right) {
            int mid = left + (right - left) / 2;
            int dayused = 1;
            int currentWeight = 0;
            for (int package : weights) {
                if (currentWeight + package <= mid) {
                    currentWeight += package;
                } else {
                    dayused++;
                    currentWeight = package;
                }
            }
            if (dayused <= days)
                right = mid;
            else
                left = mid + 1;
        }
        return right;
    }
};