#include <stdio.h>
int main()
{
    int n, m, i, s = 0;
    int f[1005], ans[1005];
    printf ("N M = ");
    scanf("%d%d", &n, &m);
    f[1] = 0;
    for (i = 2; i <= n; i++)
    {
        
        f[i] = (f[i-1] + m) % i;
        printf("%d\n",f[i]);
    }
    for (i = n; i > 1; i --) {
        // if(f[n] )
    }
    printf ("\nThe winner is %d\n", s+1);
}