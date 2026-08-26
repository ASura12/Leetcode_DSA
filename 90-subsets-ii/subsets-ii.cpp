class Solution {
public:

    void calculatesubset(vector<int>& nums,vector<int>& current,int i,vector<vector<int>> & result){
        if( i == nums.size()){
            result.push_back(current);
            return;
        }
        // Inclusion
        current.push_back(nums[i]);
        calculatesubset(nums,current,i+1,result);
        // Backtracking
        current.pop_back();
        // Exclusion
        // Important for duplication removal
        int idx = i +1;
        while(idx < nums.size() && nums[idx] == nums[idx-1]){
            idx++;
        }
        calculatesubset(nums,current,idx,result);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // First sorting and then call for subsets calculation
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int>current;
        calculatesubset(nums,current,0,result);
        return result;
    }
};