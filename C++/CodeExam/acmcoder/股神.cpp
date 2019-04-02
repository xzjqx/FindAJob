#include <stdio.h>

int main()
{
    int n;
    while(scanf("%d", &n) != EOF) {
        int sum = 1, dis = 1;
        int flag = 1, i;
        for(i = 2; i <= n;) {
            if(flag) {
                sum += dis;
                dis ++;
                i ++;
                flag = 0;
            } else {
                sum --;
                i += dis;
                flag = 1;
            }
        }
        if(flag == 0) printf("%d\n", sum);
        else printf("%d\n", sum+n-i+dis);

    }
}
