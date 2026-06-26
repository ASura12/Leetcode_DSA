class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxwater = 0;
        int lt = 0,rt = height.size()-1;
        while(lt < rt){
            int width = rt - lt;
            int h = min(height[lt],height[rt]);
            int ans = h * width;
            maxwater = max(ans,maxwater);
            height[lt] < height[rt] ? lt++:rt--;
        }
        return maxwater;
    }
};