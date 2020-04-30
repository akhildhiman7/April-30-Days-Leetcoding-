/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if (!rows) return 0;
        int cols = matrix[0].size()+1;
        int dp[++rows][cols];
        memset(dp, 0, sizeof(dp));
        int mx = 0;
        cout<<"GOT HERE";
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i-1][j-1]=='1') {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
                    mx = max(mx, dp[i][j]);
                }
            }
        }
        return pow(mx, 2);
    }
};
