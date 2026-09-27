class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        bool isPrev = false;
        int prevNum;
        int count = 0;
        int longest = 0;

        for(int num : s){

            if(isPrev){
                if(num - prevNum == 1){
                    count++;
                    longest = max(longest, count);
                    prevNum = num;
                }else{
                    count = 1;
                    prevNum = num;
                }
            }else{
                count++;
                longest = max(longest, count);
                isPrev = true;
                prevNum = num;
            }

            
        }

        return longest;
    }
};
