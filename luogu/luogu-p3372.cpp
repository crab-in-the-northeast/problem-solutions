/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-06 16:49:46 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-14 00:04:10
 */
#include <bits/stdc++.h>

const int maxn = 100005;
inline int lson(int x) {
    return x << 1;
}
inline int rson(int x) {
    return x << 1 | 1;
}
inline long long read() {
    long long x = 0;
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
    if (f) 
        return x;
    return ~(x - 1);
}

unsigned long long a[maxn << 2], ans[maxn << 2], t[maxn << 2];

inline void tag(long long x, long long l, long long r, long long k) {
    t[x] += k;
    ans[x] += k * (r - l + 1);
}

inline void pushup(long long x) {
    ans[x] = ans[lson(x)] + ans[rson(x)];
}

inline void pushdown(long long x, long long l, long long r) {
    long long mid = l + r >> 1;
    tag(lson(x), l, mid, t[x]);
    tag(rson(x), mid + 1, r, t[x]);
    t[x] = 0;
}

void build(long long x, long long l, long long r) {
    t[x] = 0;
    if (l == r) {
        ans[x] = a[l];
        return ;
    }
    long long mid = l + r >> 1;
    build(lson(x), l, mid);
    build(rson(x), mid + 1, r);
    pushup(x);
}

inline void update(long long l, long long r, long long tl, long long tr, long long x, long long k) {
    if (l <= tl && tr <= r) {
        tag(x, tl, tr, k);
        return ;
    }
    pushdown(x, tl, tr);
    long long mid = tl + tr >> 1;
    if (l <= mid)
        update(l, r, tl, mid, lson(x), k);
    if (r > mid)
        update(l, r, mid + 1, tr, rson(x), k);
    pushup(x);
    return ;
}

inline long long query(long long l, long long r, long long tl, long long tr, long long x) {
    long long res = 0;
    if (l <= tl && tr <= r)
        return ans[x];
    long long mid = tl + tr >> 1;
    pushdown(x, tl, tr);
    if (l <= mid)
        res += query(l, r, tl, mid, lson(x));
    if (r > mid)
        res += query(l, r, mid + 1, tr, rson(x));
    
    return res;
}

int main() {
    int n = read(), m = read();
    for (int i = 1; i <= n; ++i)
        a[i] = read();
    build(1, 1, n);
    while (m--) {
        int op = read();
        if (op == 1) {
            long long x = read(), y = read(), k = read();
            update(x, y, 1, n, 1, k);
        } else {
            long long x = read(), y = read();
            std :: printf("%lld\n", query(x, y, 1, n, 1));
        }
    }
    return 0;
}