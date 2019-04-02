/*
题目描述：
牛牛有两个字符串A和B,其中A串是一个01串,B串中除了可能有0和1,还可能有'?',B中的'?'可以确定为0或者1。 寻找一个字符串T是否在字符串S中出现的过程,称为字符串匹配。牛牛现在考虑所有可能的字符串B,有多少种可以在字符串A中完成匹配。

例如:A = "00010001", B = "??"
字符串B可能的字符串是"00","01","10","11",只有"11"没有出现在字符串A中,所以输出3

解题思路：
使用unordered_set集合来存储所有可能的结果，这样就能筛除重复元素。
*/
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool isMatch(string a, string b) {
    if(a.length() < b.length()) return false;
    for(int i = 0; i < b.length(); i ++) {
        if(a[i] != b[i] && b[i] != '?')
            return false;
    }
    return true;
}

int main()
{
    string a, b;
    while(cin >> a >> b) {
        unordered_set<string> set;
        for(int i = 0; i < a.length(); i ++) {
            if(isMatch(a.substr(i), b)) {
                string s = a.substr(i, b.length());
                set.insert(s);
            }
        }
        cout << set.size() << endl;
    }
    return 0;
}