class Solution {
public:
    int secondHighest(string s) {
        /*
        int highest = -1;
        int secondhighest = -1;
        vector<int>nums;
        for(char c : s){
            if(c >= '0' && c <= '9'){
                nums.push_back(c - '0');
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > highest){
                secondhighest = highest;
                highest = nums[i];
            }else if(nums[i] != highest && nums[i] > secondhighest){
                secondhighest = nums[i];
            }
        }
        return secondhighest;
        */
        int highest = -1;
        int secondhighest = -1;
        for(char c : s){
            if(c >= '0' && c <= '9'){
                int d = c - '0';
                if(d > highest){
                    secondhighest = highest;
                    highest = d; 
                }else if(d < highest && d > secondhighest){
                    secondhighest = d;
                }
            }
        }
        return secondhighest;
    }
};
/*
int highest = -1;
int secondhighest = -1;
for(char c : s){
    if(c >= '0' && c <= '9'){
        int d = c - '0';
        if(d > highest){
            secondhighest = highest;
            highest = d; 
        }else if(d < highest && d > secondhighest){
            secondhighest = d;
        }
    }
}
return secondhighest;
*/