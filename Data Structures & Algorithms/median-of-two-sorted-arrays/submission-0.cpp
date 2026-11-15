
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        int leftSize = (m + n + 1) / 2;

        while (low <= high) {

            int cut1 = low + (high - low) / 2;
            int cut2 = leftSize - cut1;

            // Four boundary elements
            int nums1Left = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int nums1Right = (cut1 == m) ? INT_MAX : nums1[cut1];

            int nums2Left = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int nums2Right = (cut2 == n) ? INT_MAX : nums2[cut2];

            // Check whether partition is valid
            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {

                // Odd total elements
                if ((m + n) % 2 != 0) {
                    return max(nums1Left, nums2Left);
                }

                // Even total elements
                return (max(nums1Left, nums2Left) +
                        min(nums1Right, nums2Right)) / 2.0;
            }

            // Move partition in nums1
            else if (nums1Left > nums2Right) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};
