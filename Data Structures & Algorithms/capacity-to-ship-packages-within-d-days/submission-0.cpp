class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int l = 0; // lower bound = height weight in arr
        int h = 0; // higher bound = sum of all ele weights
        for (int i = 0; i < n; i++) {
            l = max(l, weights[i]);
            h += weights[i];
        }

        int capacity = 0;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            int day = 1;
            int pairSum = 0;
            for (int i = 0; i < n; i++) {
                pairSum += weights[i];
                if (pairSum > mid) {
                    day++;
                    pairSum = weights[i];
                }
            }

            if (day > days) {
                l = mid + 1;
            } else {
                capacity = mid;
                h = mid-1;
            }
        }

        return capacity;
    }
};