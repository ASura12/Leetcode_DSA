class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int j = 0,i = nums.size()-1;
        int count = 0;
        while(i >= j){
            if(nums[i] == 0){
                i--;
                continue;
            }
            if(nums[j] == 0){
                swap(nums[i],nums[j]);
                i--;
                count++;
            }
            j++;
        }
        return count;
    }
};