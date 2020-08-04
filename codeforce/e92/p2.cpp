#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;
vector<int> a;

void solve(int t) {
    int n, k, z;
    int ans = 0;
    vector<int> prefix(1, 0);

    cin >> n >> k >> z;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= z; i++) {
        int sc = 0;
        int pval = -1e5;
        for (int j = 0; j <= k - 2*i; j++) {
            sc += a[j];
            if (j < n - 1 && a[j] + a[j+1] > pval)
                pval = a[j] + a[j+1];
        }
        sc += pval * i;

        ans = max(ans, sc);
    }
    cout << ans <<endl;
}

int main(int argc, char *argv[])
{
    int d;
    cin >> d;
    int t = 0;
    while(d--) {
        solve(++t);
    }

    return 0;
}
