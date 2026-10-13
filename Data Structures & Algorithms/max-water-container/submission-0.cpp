class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0;
        int j = n-1;
        int maxH2O = 0;

        while(i < j){
            int width = j-i;
            int height = min(heights[i], heights[j]);
            int H2O = width*height;
            maxH2O = max(maxH2O, H2O);
            
            if(heights[i]<heights[j]){
                i++;
            }else{
                j--;
            }
        }

        return maxH2O;
    }
};
