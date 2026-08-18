class Solution {
public:
int countstring(string s,int left,int right){
    int count = 0;
    while(left >= 0 && right < s.length() && s[left] == s[right]){
        left--;
        right++;
        count++;
    }
    return count;
}
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0;i<s.length();i++){
            count += countstring(s,i,i);
            count += countstring(s,i,i+1);
        }
        return count;
    }
};