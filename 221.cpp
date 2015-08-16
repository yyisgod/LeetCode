/*
 *	动态规划的方法
 *	dp[i,j]表示由（i，j）作为矩阵右下角时构成的最大矩阵大小
 *	dp[i][j-1]会决定能有多宽，dp[i-1][j]决定有多高，dp[i-1][j-1]则决定左上区域的大小，如果该区域的长宽不如上面两个
 *	则将由该区域来决定大小
 */
const int Len = 1000;
int dp[Len+5][Len+5];
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (n <= 0) return 0;
        int m = matrix[0].size();
        if (m <= 0) return 0;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};

