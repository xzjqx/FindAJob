#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define MAX_N 100001
#define eqs 1e-8
int n, w, a[MAX_N*2];
int main()
{
    while(cin >> n >> w) {
        int min_boy = INT_MAX, min_girl = INT_MAX;
        for(int i = 0; i < n; i ++) {
            cin >> a[i];
            if(min_boy > a[i]) min_boy = a[i];
        }
        for(int i = n; i < 2*n; i ++) {
            cin >> a[i];
            if(min_girl > a[i]) min_girl = a[i];
        }
        double m;
        if(min_boy < 2*min_girl) {
            m = min_boy / 2.0;
        } else {
            m = min_girl;
        }
        // cout << m << endl;
        if(1.0*w - 3*n*m < eqs) {
            cout << fixed << setprecision(6) << 1.0*w << endl;
        } else {
            cout<< fixed << setprecision(6) << 3*n*m << endl;
        }
    }
    return 0;
}