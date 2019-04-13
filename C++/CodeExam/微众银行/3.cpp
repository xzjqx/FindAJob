#include <iostream>
using namespace std;

int main()
{
    int T, n;
    cin >> T;
    while(T --) {
        cin >> n;
        int sum = 0;
        while(n != 1) {
            sum ++;
            if(n % 2) n = 3*n + 1;
            else n = n / 2;
        }
        cout << sum << endl;
    }
}