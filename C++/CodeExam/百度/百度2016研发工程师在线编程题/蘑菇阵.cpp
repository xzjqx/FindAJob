#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_K 105
#define MAX_N 25

int n, m, k;
int x[MAX_K], y[MAX_K];
int ma[MAX_N][MAX_N];
double dp[MAX_N][MAX_N][3];

int main()
{
    while(scanf("%d %d %d", &n, &m, &k) != EOF) {
        memset(ma, 0, sizeof(ma));
        for(int i = 0; i < k; i ++) {
            scanf("%d %d", &x[i], &y[i]);
            ma[x[i]][y[i]] = 1;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][1][1] = 0.5;
        dp[1][0][2] = 0.5;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                dp[i][j][0] = (ma[i][j]) ? 0 : (dp[i-1][j][1] + dp[i][j-1][2]);
                if(i == n && j == m) {
                    dp[i][j][1] = 0;
                    dp[i][j][2] = 0;
                } else if(i == n) {
                    dp[i][j][1] = 0;
                    dp[i][j][2] = dp[i][j][0];
                } else if(j == m) {
                    dp[i][j][1] = dp[i][j][0];
                    dp[i][j][2] = 0;
                } else {
                    dp[i][j][1] = 0.5*dp[i][j][0];
                    dp[i][j][2] = 0.5*dp[i][j][0];
                }
            }
        }
        printf("%.2f\n", dp[n][m][0]);
    }
    return 0;
}
