class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = INT_MAX;
        int start =0,end = nums.size() - 1;
        while(start <= end){
            int mid = start + (end - start)/2;
            mini = min(mini,nums[mid]);
            //Left part is sorted
            if(nums[start] <= nums[mid]){
                mini = min(mini,nums[start]);
                start = mid + 1;
            }
            // Right part is sorted
            else{
                    mini = min(mini,nums[end]);
                    end = mid - 1;
            }
        }
        return mini;
    }
};