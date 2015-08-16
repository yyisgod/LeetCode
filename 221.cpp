/*
 *	��̬�滮�ķ���
 *	dp[i,j]��ʾ�ɣ�i��j����Ϊ�������½�ʱ���ɵ��������С
 *	dp[i][j-1]��������ж��dp[i-1][j]�����ж�ߣ�dp[i-1][j-1]�������������Ĵ�С�����������ĳ�������������
 *	���ɸ�������������С
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

