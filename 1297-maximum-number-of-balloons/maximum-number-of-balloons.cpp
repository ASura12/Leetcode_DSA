class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>freq(26,0);
        for(char ch: text){
            freq[ch - 'a']++;
        }
        return min({freq[1],    // 'b'
                    freq[0],    // 'a'
                    freq[11] / 2,   // 'l',
                    freq[14] / 2,   // 'o',
                    freq[13]}); // 'n'
    }
};