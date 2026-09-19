class Solution {
public:
    void reverseString(vector<char>& s) {
       int st = 0;
       int et = s.size()-1;

       while(st <= et){
        swap(s[st], s[et]);
        st++;
        et--;
       }
       
    }
};