class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int m1 = 0;
        int countM1 = 0;
        int m2 = 0;
        int countM2 = 0;

        for(int num : nums){
            if(num == m1){
                countM1++;
            } 
            else if(num == m2){
                countM2++;
            } 
            else if(countM1 == 0){
                m1 = num;
                countM1 = 1;
            } 
            else if(countM2 == 0){
                m2 = num;
                countM2 = 1;
            } 
            else{
                countM1--;
                countM2--;
            }
        }

        countM1 = 0;
        countM2 = 0;

        for(int num : nums){
            if(num == m1) {
                countM1++;
            }
            else if(num == m2) {
                countM2++;
            }
        }

        vector<int> result;

        if(countM1 > n/3){
            result.push_back(m1);
        }

        if(countM2 > n/3){
            result.push_back(m2);
        }

        return result;
    }
};