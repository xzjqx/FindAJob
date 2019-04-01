#include <stdio.h>

#define MAX_N 200005

int n, t, c, ans;
int a[MAX_N];

int main()
{
    while(scanf("%d %d %d", &n, &t, &c) != EOF) {
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        ans = 0;
        for(int i = 0; i <= n-c; i ++) {
            int sum = 0;
            for(int j = i; j < c+i; j ++) {
                sum += a[j];
            }
            if(sum <= t) ans ++;
        }
        printf("%d\n", ans);
    }
    return 0;
}