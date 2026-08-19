class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        vector<int> pi(26,0), si(26,0);
        int left = 0,right = 0;
        // Entering all the count of string p
        while(right < p.size()){
            pi[p[right] - 'a']++;
            si[s[right] - 'a']++;
            right++;
        }
        right--;
        vector<int> ans;
        while(right < s.size()){
            if(si == pi){
                ans.push_back(left);
            }
            // Removing the leftmost character
            si[s[left] - 'a']--;
            left++;
            right++;
            if(right != s.size()){
                // Putting next character into it
                si[s[right] - 'a']++;
            }
        }
        return ans;
    }
};