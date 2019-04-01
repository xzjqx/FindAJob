#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX_N 1005
#define eps 1e-6

int n, m, x, y, t;
double Map[MAX_N][MAX_N];

int main()
{
    while(scanf("%d %d %d %d %d", &n, &m, &x, &y, &t) != EOF) {
        memset(Map, 0, sizeof(Map));
        int nodes = n * m;
        double sum = 0;
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= m; j ++) {
                scanf("%lf", &Map[i][j]);
                sum += Map[i][j];
            }
        double cc = Map[x][y], ss = 1;
        double tmp = 1.0 - sum / nodes;
        for(int i = 0; i < t; i ++)
            ss *= tmp;
        ss = 1.0 - ss;
        printf("%f\n", ss);
        if(abs(cc-ss) < eps)
            printf("equal\n%.2f\n", cc);
        else if(cc-eps > ss)
            printf("cc\n%.2f\n", cc);
        else
            printf("ss\n%.2f\n", ss);
    }
    return 0;
}
