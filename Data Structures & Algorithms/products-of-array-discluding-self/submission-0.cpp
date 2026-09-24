class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        int prod = 1;
        int count0 = 0;

        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                prod *= nums[i];
            }else{
                count0++;
            }
        }

        if(count0 > 1){
            return vector<int>(n, 0);
        }

        vector<int> output(n);

        for(int i=0; i<n; i++){
            if (count0 > 0) {
                output[i] = (nums[i] == 0) ? prod : 0;
            } else {
                output[i] = prod / nums[i];
            }
        }

        return output;
    }
};
