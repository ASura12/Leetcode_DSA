class Solution {
public:
    int firstOcc(vector<int> &arr,int key,bool isSearchingLeft){
        int s = 0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;
        int ans = -1;
        while(e >= s){
            if(key > arr[mid]){
                s = mid + 1;
            }else if(key < arr[mid]){
                e = mid -1;
            }else{
                ans = mid;
                if(isSearchingLeft){
                    e = mid - 1;
                }else{
                    s = mid + 1;
                }
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> result = {-1, -1};
        int FirstOcc = firstOcc(nums,target,true);
        int LastOcc = firstOcc(nums,target,false);
        result[0] = FirstOcc;
        result[1] = LastOcc;
        return result;    
    }
};