#include <stdio.h>
#include <limits.h>

#define MAX_N 100005

int main()
{
    int n, a[MAX_N];
    while(scanf("%d", &n) != EOF) {
        int flag = 0, cnt = 0;
        scanf("%d", &a[0]);
        int tmp = INT_MIN;
        for(int i = 1; i < n; i ++) {
            scanf("%d", &a[i]);
            if(a[i] < a[i-1]) {
                if(i > 1) tmp = a[i-2];
                cnt ++;
                int j;
                for(j = i + 1; j < n; j ++) {
                    scanf("%d", &a[j]);
                    if(a[j] > a[j-1]) {
                        break;
                    }
                }
                if(a[j-1] < tmp || a[j] < a[i-1]) flag = 1;
                i = j;
            }
        }
        if(cnt > 1 || flag) printf("no\n");
        else printf("yes\n");
    }
}
