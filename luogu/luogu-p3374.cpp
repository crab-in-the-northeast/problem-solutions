/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-06 16:41:35 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-06 16:48:17
 */
#include <bits/stdc++.h>

const int maxn = 500005 * 4;
int a[maxn], n;
inline int read() {
    int x = 0;
    bool f = true;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = false;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    if (f) return x;
    return ~(x - 1);
}
inline int lowbit(int x) {
    return x & (-x);
}

int getsum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += a[i];
    return sum;
}

void update(int x, int val) {
    for (int i = x; i <= n; i += lowbit(i))
        a[i] += val;
}

int main() {
    n = read();
    int m = read();
    for (int i = 1; i <= n; ++i)
        update(i, read());
    while (m--) {
        int op = read();
        if (op == 1) {
            int x = read(), val = read();
            update(x, val);
        } else {
            int l = read(), r = read();
            std :: printf("%d\n", getsum(r) - getsum(l - 1));
        }
    }
    return 0;
}