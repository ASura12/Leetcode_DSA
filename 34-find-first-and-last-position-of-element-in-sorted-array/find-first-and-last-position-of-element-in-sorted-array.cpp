class Solution {
public:

    int search(vector<int>&nums,int target,bool isleft){
        int start = 0,end = nums.size()-1;
        int ans = -1;
        while(start<=end){
            int mid = start + (end- start)/2;
            if(nums[mid] > target){
                end = mid -1;
            }else if(nums[mid] < target){
                start = mid + 1;
            }else{
                ans = mid;
                if(isleft){
                    end = mid-1;
                }else{
                    start = mid + 1;
                }
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1,-1};
        int First = search(nums,target,true);
        int last = search(nums,target,false);
        result[0] = First;
        result[1] = last;
        return result;
    }
};