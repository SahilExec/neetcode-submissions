class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> res;

        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int k = n - 1; k > i; k--) {
                if (k < n-1 && nums[k+1] == nums[k]) {
                    continue;
                }
                int j = i + 1;
                int l = k - 1;

                while (j < l) {
                    long long sum = 1LL * nums[i] + nums[j] + nums[l] + nums[k];

                    if (sum < target) {
                        j++;
                    } else if (sum > target) {
                        l--;
                    } else {
                        res.push_back({nums[i], nums[j], nums[l], nums[k]});
                        j++;
                        l--;

                        while (j < l && nums[j] == nums[j - 1]) {
                            j++;
                        }

                        while (j < l && nums[l] == nums[l + 1]) {
                            l--;
                        }
                    }
                }
            }
        }

        return res;
    }
};