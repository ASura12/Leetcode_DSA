class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxsum = 0;
        long long sum = 0;
        unordered_map<int,int>mp;
        int left = 0;
        for(int right = 0;right < nums.size();right++){
            sum+= nums[right];
            mp[nums[right]]++;
            if(right - left + 1 == k){
                if(mp.size() == k){
                    maxsum = max(maxsum,sum);
                }
                sum -= nums[left];
                mp[nums[left]]--;
                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }
        }
        return maxsum;
    }
};