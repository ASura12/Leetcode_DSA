class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi = INT_MIN;
        int left = 0;
        double sum =0;
        for(int right = 0;right<nums.size();right++){
            sum+=nums[right];
            if(right - left+1 == k){
                maxi = max(maxi,sum);
                sum -= nums[left];
                left++;
            }
        }
        return maxi/k;
    }
};