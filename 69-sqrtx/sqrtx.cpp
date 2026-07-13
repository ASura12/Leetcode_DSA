class Solution {
public:
    int binarysearch(int target){
        int st = 0;
        int en = target;
        long long int mid = st + (en - st)/2;
        long long int ans = 0;
        while(st<= en){
            long long int square = mid * mid;
            if(square == target) return mid;
            else if(square < target){
                ans = mid;
                st = mid + 1;
            }
            else{
                en = mid - 1;
            }
            mid = st + (en - st)/2;
        }
        return ans;
    }
    int mySqrt(int x) {
        return binarysearch(x);
    }
};