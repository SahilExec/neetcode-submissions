class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int li = 0;
        int lj = 0;
        int hi = 0;
        int hj = n-1;
        while(hi<m){
            if(target > matrix[hi][hj]){
                hi++;
            }else{
                while(lj <= hj){
                    int midj = lj + (hj-lj)/2;
                    if(target == matrix[hi][midj]){
                        return true;
                    }else if(target > matrix[hi][midj]){
                        lj = midj+1;
                    }else{
                        hj = midj-1;
                    }
                }
                return false;
            }
        }

        return false;
    }
};
