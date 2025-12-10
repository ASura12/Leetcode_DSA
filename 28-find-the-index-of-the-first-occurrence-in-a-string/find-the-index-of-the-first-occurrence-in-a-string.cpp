class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0,j = 0;
        while(i < haystack.size()){
            if(needle[j] == haystack[i]){
                j++;
                i++;
                if(j == needle.size()){
                    return i - j;
                }
            }else{
                i = i-j + 1;  // reset i to the next element
                j = 0;        // reset j to 0
            }
        }
        return -1;
    }
};