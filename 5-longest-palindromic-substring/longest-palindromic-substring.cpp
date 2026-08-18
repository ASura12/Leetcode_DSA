class Solution {
public:

    string expandAroundcenter(string s,int left,int right){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }

    string longestPalindrome(string s) {
        if(s.empty()) return "";
        string longest = "";
        for(int i = 0;i<s.length();i++){
            // For ODD string
            string p1 = expandAroundcenter(s,i,i);
            if(p1.length() > longest.length()) longest = p1;
            // For EVEN string
            string p2 = expandAroundcenter(s,i,i+1);
            if(p2.length() > longest.length()) longest = p2;
        }
        return longest;
    }
};