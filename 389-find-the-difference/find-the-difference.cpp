class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp;
        
        for(char c : s) mp[c]++;
        for(char c : t) mp[c]--;

        for(auto &p : mp){
            if(p.second != 0){
                return p.first;
            }
        }

        return 0;
    }
};
