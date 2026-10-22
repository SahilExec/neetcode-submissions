class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int n = people.size();
        int l = 0;
        int h = n - 1;
        
        int res = 0;

        while (l <= h) {
            int left = limit - people[h];
            h--;
            res++;

            if (l <= h && people[l] <= left) {
                l++;
            }
        }
        return res;
    }
};