class Solution {
public:
    int Getgcd(int a,int b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i = 0;i <nums.size();i++){
            if(nums[i] > maxi){
                maxi = nums[i];
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i] < mini){
                mini = nums[i];
            }
        }
        int ans = Getgcd(mini,maxi);
        return ans;
    }
};