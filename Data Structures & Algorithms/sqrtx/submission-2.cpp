class Solution {
public:
    int mySqrt(int x) {
        int l = 0, h = x;
        int sqrt = 0;

        while (l <= h) {
            int m = l + (h - l) / 2;
            if (1LL * m * m > x) {
                h = m - 1;
            } else if (1LL * m * m < x) {
                l = m + 1;
                sqrt = m;
            } else {
                return m;
            }
        }

        return sqrt;
    }
};