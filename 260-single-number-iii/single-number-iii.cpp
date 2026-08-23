class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        // First perform the XOR operation
        int xored = 0;
        for(int &num : nums){
            xored ^= num;
        }
        // Now find the exhibit bit which tell us which is setbit or unsetbit
        int exhibit = 0;
        while(true){
            if((xored & 1) == 1) break;
            xored = xored >> 1;
            exhibit++;
        }

        // distinguish setbit and unsetbit and we perform the xor operation which will give us the both the unique numbers
        int setbit = 0;
        int unsetbit = 0;
        for(int &num:nums){
            if(((num >> exhibit) & 1) ==1){
                setbit ^= num;
            }else{
                unsetbit ^= num;
            }
        }
        ans.push_back(setbit);
        ans.push_back(unsetbit);
        return ans;
    }
};