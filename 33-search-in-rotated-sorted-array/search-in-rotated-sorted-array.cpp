class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size()-1;
        while(st <= end){
            int mid = st + (end - st)/2;
            if(nums[mid] == target){
                return mid;
            }
            //Left Sorted 
            if(nums[st] <= nums[mid]){
                //Left Search phase if target lies between start and mid 
                if(nums[st] <= target && target <= nums[mid]){
                    end = mid -1;
                }else{
                    // Search in right phase
                    st = mid + 1;
                }
            }
            //Right Sorted 
            else{
                //Right Search phase if target lies between start and mid 
                if(nums[mid] <= target && target <= nums[end]){
                    st = mid + 1;
                }else{
                    // Search in left phase
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};