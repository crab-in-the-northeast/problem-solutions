/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-08 21:40:08 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-08 23:18:13
 */
#include <iostream>
#include <cstdio>

std :: string s;

void FBI(int l, int r) {
    int mid = (l + r) >> 1;
    if(l < r) {
        FBI(l, mid);
        FBI(mid + 1, r);
    }
    for(int i = l + 1; i <= r; i++)
        if(s[i] != s[i - 1] && i != 1) {
            putchar('F');
            return ;
        }
    if(s[l] == '0') putchar('B');
    else putchar('I');
    return ;
}

int main() {
    int n;
    std :: cin >> n;
    std :: cin >> s;
    s = " " + s;
    FBI(1, 1 << n);
    return 0;
}
