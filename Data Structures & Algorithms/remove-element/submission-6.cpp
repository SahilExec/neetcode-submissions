class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int st = 0;
        int lst = n-1;
        while(st<=lst){
            while(st <= lst && nums[lst] == val ){
                lst--;
            }

            if(st <= lst && nums[st] == val){
                swap(nums[st], nums[lst]);
            }
            else{
                st++;
            }
        }

        return lst+1;
    }
};