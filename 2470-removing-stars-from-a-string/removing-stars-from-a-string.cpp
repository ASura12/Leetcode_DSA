class Solution {
public:
    string removeStars(string s) {
        string st="";
        stack<char> str;
        for(char ch: s){
            if(ch == '*'){
                if(!str.empty()){
                    str.pop();
                }
            }else{
                str.push(ch);
            }
        }
        while(!str.empty()){
            st += str.top();
            str.pop();
        }
        reverse(st.begin(),st.end());
        return st;
    }
};