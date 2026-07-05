class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        long long int prod = 1;
        int left = 0;
        for(int right = 0;right < nums.size();right++){
            prod = prod * nums[right];
            while(prod >= k){
                prod /= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
};