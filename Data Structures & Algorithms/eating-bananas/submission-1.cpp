class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long hours = 0;

            for (int i = 0; i < n; i++) {
                hours += piles[i] / mid;

                if (piles[i] % mid > 0) {
                    hours++;
                }
            }

            if (hours > h) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }

        return low;
    }
};