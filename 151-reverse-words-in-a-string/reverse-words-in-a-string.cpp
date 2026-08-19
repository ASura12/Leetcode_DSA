class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0, idx = 0;
        
        // 1. Reverse the entire string first
        reverse(s.begin(), s.end());
        
        // 2. Traverse and fix word positions/spaces in-place
        while (i < n) {
            // Skip leading/extra spaces
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;
            
            // Add a space between words (if it's not the first word)
            if (idx != 0) s[idx++] = ' ';
            
            // Copy the word characters
            int j = i;
            while (j < n && s[j] != ' ') s[idx++] = s[j++];
            
            // Reverse the word back to its correct reading orientation
            reverse(s.begin() + idx - (j - i), s.begin() + idx);
            
            i = j;
        }
        
        // Resize string to remove leftover trailing characters
        s.resize(idx);
        return s;
    }
};
