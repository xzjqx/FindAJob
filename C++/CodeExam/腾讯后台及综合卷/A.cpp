#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int gcd( int a, int b ) {
    return ( ( b == 0 ) ? a : gcd( b, a % b ) );
}

int lcm( int a, int b ) {
    return ( a / gcd( a, b ) * b );
}

int main()
{
    int m, n, a[105];
    while(cin >> m >> n) {
        int dp1[20005];
        for(int i = 0; i < n; i ++)
            cin >> a[i];
        int l = a[0];
        for(int i = 1; i < n; i ++)
            l = lcm(l, a[i]);
        cout << l << endl;
        dp1[0] = 0;
        int flag = 0;
        for(int i = 1; i <= l; i ++) {
            int tmp = INT_MAX;
            for(int j = 0; j < n; j ++) {
                if(i >= a[j]) {
                    tmp = (tmp > (dp1[i-a[j]] + 1)) ? (dp1[i-a[j]] + 1) : tmp;
                }
            }
            dp1[i] = tmp;
            if(dp1[i] == INT_MAX) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            cout << -1 << endl;
            continue;
        }
        cout << dp1[l] << endl;

        int dp2[20005];
        dp2[0] = 0;
        dp2[1] = dp1[1];
        for(int i = 2; i <= l; i ++) {
            dp2[i] = dp2[i/2] + dp1[i/2];
            cout << "i = " << i << ":" << dp2[i] << endl;
        }
        cout << dp2[l] << endl;
        if(m % l == 0) {
            cout << m / l - 1 + dp2[l] << endl;
        } else {
            cout << m / l + dp2[l] << endl;
        }
    }
    return 0;
}