#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

#define MAX_N 1005

int n, x[MAX_N], y[MAX_N];

int main()
{
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; i ++)
            scanf("%d %d", &x[i], &y[i]);
        long long x_min = INT_MAX, y_min = INT_MAX, x_max = INT_MIN, y_max = INT_MIN;
        for(int i = 0; i < n; i ++) {
            if(x[i] < x_min) x_min = x[i];
            if(y[i] < y_min) y_min = y[i];
            if(x[i] > x_max) x_max = x[i];
            if(y[i] > y_max) y_max = y[i];
        }
        int y_dis = y_max-y_min, x_dis = x_max-x_min;
        int r = max(y_dis, x_dis);
        printf("%d\n", r * r);
    }
    return 0;
}