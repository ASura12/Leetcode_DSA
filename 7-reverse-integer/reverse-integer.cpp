class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while(x != 0){
            int ans = x % 10;
            if ((rev > INT_MAX / 10) || (rev < INT_MIN / 10)) {
                return 0; // Return 0 if reversing x would cause overflow/underflow
            }
            rev = ans + rev * 10;
            x = x / 10;
        }
        return rev;
    }
};