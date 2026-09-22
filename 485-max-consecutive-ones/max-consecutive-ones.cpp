class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0, maxcount = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                left = right + 1;
            }
            maxcount = max(maxcount, right - left + 1);
        }
        return maxcount;
    }
};