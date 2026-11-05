class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int l = 0; // lower bound = max element in nums
        int h = 0; // higher bound = sum of all elements
        for (int i = 0; i < n; i++) {
            l = max(l, nums[i]);
            h += nums[i];
        }

        while(l<h){
            int mid = l + (h-l)/2;

            int countSub = 1;
            int sumSub = 0;
            for(int i=0; i<n; i++){
                sumSub += nums[i];
                if(sumSub>mid){
                    countSub++;
                    sumSub = nums[i];
                }
            }

            if(countSub>k){
                l = mid + 1;
            }else{
                h = mid;
            }
        }

        return l;
    }
};