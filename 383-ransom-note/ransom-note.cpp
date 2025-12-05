class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> need, have;

        for (char c : ransomNote) need[c]++;
        for (char c : magazine)   have[c]++;

        for (auto &p : need) {
            char ch = p.first;
            int req = p.second;
            if (have[ch] < req) return false;
        }

        return true;
    }
};
