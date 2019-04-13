#include <iostream>
using namespace std;

int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    if(n <= m) 
        cout << k << endl;
    if(n % m == 0)
        cout << k*n/m << endl;
    else
        cout << k*n/m + 1 << endl;
}