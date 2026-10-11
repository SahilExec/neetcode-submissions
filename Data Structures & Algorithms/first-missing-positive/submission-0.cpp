class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // all -ve and greater then to n+1
        for(int i=0; i<n; i++){
            if(nums[i] <= 0 || nums[i] > n){
               nums[i] = n+1;
            }
        }

        // now we have'nt any -ve
        // now we mark -ve, value of prev idx of curr value as idx except n+1 only when its not already negative because to prevent from duplicate issue
        for(int i=0; i<n; i++){
            if(abs(nums[i]) != n+1 && nums[abs(nums[i]) - 1] > 0){
                nums[abs(nums[i]) - 1] = - nums[abs(nums[i]) - 1];
            }
        }

        for(int i=0; i<n; i++){
            if(nums[i] > 0){
                return i+1;
            }
        }

        return n+1;

    }
};