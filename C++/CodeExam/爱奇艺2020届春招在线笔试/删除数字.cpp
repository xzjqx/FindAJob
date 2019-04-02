#include <stdio.h>
#include <cstring>

int main()
{
    char A[245];
    int k, num[245];
    while(scanf("%s %d", A, &k) != EOF) {
        int n = strlen(A);
        if(n == 0) {
            printf("\n");
            continue;
        }
        for(int i = 0; i < n; i ++) {
            num[i] = A[i] - '0';
        }
        while(k --) {
            int i;
            for(i = 0; i < n-1; i ++) {
                if(num[i] > num[i+1]) break;
            }
            n --;
            for(int j = i; j < n; j ++)
                num[j] = num[j+1];
        }
        int i;
        for(i = 0; i < n; i ++) {
            if(num[i] != 0) break;
        }
        if(i == n) printf("0");
        for(int j = i; i < n; i ++)
            printf("%d", num[i]);
        printf("\n");
    }
}
