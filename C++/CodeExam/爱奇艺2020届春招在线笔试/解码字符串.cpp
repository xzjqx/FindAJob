#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string func(string str) {
    int len = str.length();
    int n, flag = 0, i = -1, j = -1;
    for(i = 0;i < len; i ++) {
        if(str[i] >= '0' && str[i] <= '9') {
            for(j = i+1; j < len; j ++) {
                if(str[j] == '[') {
                    string s1 = str.substr(i, j-i);
                    n = atoi(s1.c_str());
                    flag = 1;
                    break;
                }
            }
            if(flag) break;
        }
    }
    if(!flag) return str;
    int pos;
    for(pos = len - 1; pos > j; pos --)
        if(str[pos] == ']') break;
    string s2 = str.substr(j+1, pos-j-1);
    string s3 = func(s2);
    for(int k = 1; k < n; k ++) {
        s3 += func(s2);
    }
    s3 += str.substr(pos+1, len-pos-1);
    return str.substr(0, i) + s3;;
}

int main()
{
    string str;
    while(cin >> str) {
        cout << func(str) << endl;
    }
    return 0;
}
