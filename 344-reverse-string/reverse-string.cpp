class Solution {
public:
    void reverseString(vector<char>& s) {
        int ft = 0,e = s.size()-1;
        while(ft < e){
            swap(s[ft],s[e]);
            ft++;e--;
        }
    }
};