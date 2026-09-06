class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        unordered_set<int> zeroRows, zeroCols;

        // Pass 1: just record, don't mutate
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        // Pass 2: apply
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (zeroRows.count(i) || zeroCols.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};