class NumMatrix {
public:
    vector<vector<int>> prefix;

    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Extra row and column of 0 for boundry
        prefix = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));

        for(int i = 1; i <= rows; i++) {
            for(int j = 1; j <= cols; j++) {

                int current = matrix[i - 1][j - 1];
                int top = prefix[i - 1][j];
                int left = prefix[i][j - 1];
                int topLeft = prefix[i - 1][j - 1];

                prefix[i][j] = current + top + left - topLeft;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {

        // Convert matrix coords to prefix coords
        row1++;
        col1++;
        row2++;
        col2++;

        int whole = prefix[row2][col2];
        int top = prefix[row1 - 1][col2];
        int left = prefix[row2][col1 - 1];
        int topLeft = prefix[row1 - 1][col1 - 1];

        return whole - top - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */