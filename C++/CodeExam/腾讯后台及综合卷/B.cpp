#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string str;
    while(cin >> n >> str) {
        int sum_0 = 0, sum_1 = 0;
        for(int i = 0; i < n; i ++) {
            if(str[i] == '0') sum_0 ++;
            else if(str[i] == '1') sum_1 ++;
        }
        cout << abs(sum_0 - sum_1) << endl;
    }
    return 0;
}