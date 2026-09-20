class Solution {
public:
    void sortColors(vector<int>& nums) {
        int st = 0;
        int et = nums.size()-1;

        int i = 0;
        while(i <= et){
            if(nums[i] == 0){
                swap(nums[i], nums[st++]);
            }else if(nums[i] == 2){
                swap(nums[i], nums[et--]);
                i--;
            }
            i++;
        }
    }
};