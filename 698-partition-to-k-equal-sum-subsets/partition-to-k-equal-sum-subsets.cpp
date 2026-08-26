class Solution {
public:
    bool canPartition(vector<int>& nums, vector<bool>& visited, int start, int k, int currSum, int subsetsum) {
        if (k == 0) return true;
        if (currSum == subsetsum) {
            // Start next subset from index 0
            return canPartition(nums, visited, 0, k - 1, 0, subsetsum);
        }

        for (int i = start; i < nums.size(); i++) {
            if (visited[i]) continue;
            if (currSum + nums[i] > subsetsum) continue; // Prune: exceeds target

            visited[i] = true;
            if (canPartition(nums, visited, i + 1, k, currSum + nums[i], subsetsum)) return true;
            visited[i] = false;

            // --- CRITICAL PRUNING STEP 1 ---
            // If this was the first element of a new subset and it failed,
            // this partition layout is fundamentally impossible. Break early.
            if (currSum == 0) return false;

            // --- CRITICAL PRUNING STEP 2 ---
            // Skip duplicate identical elements since they will produce the same failure.
            while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                i++;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalsum = 0;
        for (int x : nums) totalsum += x;
        
        if (totalsum % k != 0 || nums.size() < k) return false;
        
        int subsetsum = totalsum / k;
        
        // --- CRITICAL PRUNING STEP 3 ---
        // Sort descending so larger elements are placed first. 
        // This hits capacity bounds much faster and prunes dead ends early.
        sort(nums.rbegin(), nums.rend()); 
        if (nums[0] > subsetsum) return false; 

        vector<bool> visited(nums.size(), false);
        return canPartition(nums, visited, 0, k, 0, subsetsum);
    }
};
