#include <iostream>
using namespace std;

#define MOD 666666666
int n, ans;

long long fib(int n) {
    if(n == 6) return 1;
    if(n == 7) return 2;
    return (fib(n-1) + fib(n-2) + 1) % MOD;
}

int main()
{
    while(cin >> n) {
        if(n < 6) {
            cout << 0 << endl;
            continue;
        }
        cout << fib(n) << endl;
    }
}