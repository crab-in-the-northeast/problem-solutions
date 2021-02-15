/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-11-06 16:30:52 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-11-06 16:35:20
 */
#include <bits/stdc++.h>

const double eps = 1e-6;
const int maxn = 15;
int n;
double a[maxn];

double cal(double x) {
    double sum = 0;
    for (int i = n; i >= 0; --i)
        sum = sum * x + a[i];
    return sum;
}

int main() {
    double l, r;
    std :: scanf("%d %lf %lf", &n, &l, &r);
    for (int i = n; i >= 0; --i)
        std :: scanf("%lf", &a[i]);
    
    while (fabs(l - r) >= eps) {
        double mid = (l + r) / 2;
        if (cal(mid + eps) > cal(mid - eps))
            l = mid;
        else
            r = mid;
    }

    std :: printf("%.5lf\n", r);
    return 0;
}