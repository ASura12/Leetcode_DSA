class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>result;
        for(int i = 1;i<=n;i++){
            string res = "";
            if(i % 3 == 0){
                res += "Fizz";
            }
            if(i % 5 == 0){
                res += "Buzz";
            }
            if(res.empty()){
                res += to_string(i);
            }
            result.push_back(res);
        }
        return result;
        
    }
};