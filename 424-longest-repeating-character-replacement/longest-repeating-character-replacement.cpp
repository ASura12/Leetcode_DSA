class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int maxcount = 0;int maxlength = 0;
        int left = 0;
        for(int right = 0;right < s.size();right++){
            mp[s[right]]++;
            maxcount = max(maxcount,mp[s[right]]);
            int winlength = right - left + 1;
            if(winlength - maxcount > k){
                mp[s[left]]--;
                left++;
            }
            maxlength = max(maxlength,right-left+1);
        }
        return maxlength;
    }
};