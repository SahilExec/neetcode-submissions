class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> pre;

        int currPre = 0;
        pre[0] = 1;
        
        int count = 0;
        for(int i=0; i<n; i++){
            currPre += nums[i];
            if(pre.count(currPre - k)){
                count += pre[currPre - k];
            }
            pre[currPre]++;
        }

        return count;
    }
};