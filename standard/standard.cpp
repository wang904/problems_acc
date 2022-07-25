#include <iostream>

#include <cstdio>

#include <algorithm>

#include <cmath>

#include <set>

#include <cstring>

#include <stack>

#include <set>

#include <vector>

#include <queue>

#define Swap(a,b)  a ^= b ^= a ^= b

#define pi acos(-1)

#define cl(a,b) memset(a,b,sizeof(a))

using namespace std;

typedef long long LL;

//const int N = 1e7+10 ;

const int inf = 0x3f3f3f3f;

const int MAX = 1e5 + 5;

double a[MAX];

double sum[MAX];



int main()

{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int n, f;

    double l = -1e6, r = 1e6;

    cin >> n >> f;



    for (int i = 1; i <= n; i++) {

        scanf("%lf", &a[i]);


    }

    double eps = 1e-5;



    while (r - l > eps) {

        double mid = (l + r) / 2;


        for (int i = 1; i <= n; i++) {

            // 前缀和

            sum[i] = sum[i - 1] + a[i] - mid;

        }

        double ans = -1e10;

        double minn = 1e10;

        for (int i = f; i <= n; i++) {

            minn = min(minn, sum[i - f]);

            ans = max(ans, sum[i] - minn); // 大于等于 L长度 的子序列的和,每次都取最大,单调增

        }

        if (ans >= 0) {

            l = mid;

        }

        else {

            r = mid;

        }

    }

    printf("%d\n", int(r * 1000));

    return 0;

}