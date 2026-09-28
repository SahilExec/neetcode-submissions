class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for(int num : s){
            int count = 1;
            int next = num+1;
            if(s.count(num-1) == 0){

                while(s.count(next)){
                    count++;
                    next++;
                }
            }
            
            longest = max(longest, count);
        }

        return longest;
    }
};
