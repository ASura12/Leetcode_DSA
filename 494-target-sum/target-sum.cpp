class Solution {
public:
    int countsubsetsum(vector<int>& arr, int sum) {
        int n = arr.size();
        int t[n + 1][sum + 1];
        int mod = 1e9 + 7;

        // 1. FIXED INITIALIZATION LOGIC (Only t[0][0] is 1, rest are 0)
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < sum + 1; j++) {
                if (i == 0 && j == 0) {
                    t[i][j] = 1;
                } else {
                    t[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n + 1; i++) {
            // Starting j from 0 correctly computes configurations containing 0
            for (int j = 0; j < sum + 1; j++) {
                if (arr[i - 1] <= j) {
                    // 2. FIXED OPERATOR PRECENDENCE MODULO
                    t[i][j] = (t[i - 1][j] + t[i - 1][j - arr[i - 1]]) % mod;
                } else {
                    t[i][j] = t[i - 1][j];
                }
            }
        }
        return t[n][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum_of_arr = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum_of_arr += nums[i];
        }

        // 3. FIXED EDGE CASES: Sum partition parity and threshold validations
        if (abs(target) > sum_of_arr ||(sum_of_arr + target) % 2 != 0 || target > sum_of_arr) {
            return 0;
        }

        int sum = (sum_of_arr + target) / 2;
        return countsubsetsum(nums, sum);
    }
};