class Solution {
public:
    void subsetsentry(vector<int>& nums, vector<int>& current, int i, vector<vector<int>>& result) {
        if (i == nums.size()) {
            result.push_back(current); // Store the subset
            return;
        }
        
        // Include current element
        current.push_back(nums[i]);
        subsetsentry(nums, current, i + 1, result);
        
        // Backtrack
        current.pop_back();
        
        // Exclude current element
        subsetsentry(nums, current, i + 1, result);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        subsetsentry(nums, current, 0, result);
        return result;
    }
};
