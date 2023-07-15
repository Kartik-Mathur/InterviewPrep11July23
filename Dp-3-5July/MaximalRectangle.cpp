class Solution {
public:
    int maximalSquare(vector<vector<char>>& a) {
        int rows = a.size();
        int cols = a[0].size();

        vector<vector<int> > dp(rows + 1, vector<int>(cols + 1, 0));
        int ans = 0;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (i == 0 || j == 0) {
                    dp[i][j] = (a[i][j] - '0' );
                }
                else {
                    if (a[i][j] == '1') {
                        dp[i][j] = min(dp[i][j - 1],
                                       min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
                    }
                }

                ans = max(ans, dp[i][j] * dp[i][j]);
            }
        }

        // for (int i = 0; i < rows; ++i)
        // {
        //     for (int j = 0; j < cols; ++j)
        //     {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return ans;
    }
};