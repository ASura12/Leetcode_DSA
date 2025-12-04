class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            mp[x].push_back(i);
            
            int sz = mp[x].size();
            if (sz >= 3) {
                int i1 = mp[x][sz-3];
                int i2 = mp[x][sz-2];
                int i3 = mp[x][sz-1];

                int dist = abs(i1 - i2) + abs(i1 - i3) + abs(i2 - i3);

                ans = min(ans, dist);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
