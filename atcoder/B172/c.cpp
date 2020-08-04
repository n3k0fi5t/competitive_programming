#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

void solve(int t) {
    int n;
    cin >> n;
}

vector<ll> a,b;
int n, m, k;
int main(int argc, char *argv[])
{
    int ans = 0;
    cin >> n >> m >> k;
    a.resize(n+1, 0);
    b.resize(m+1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        b[i] += b[i-1];
    }

    for (int i = 0, j = m; i <= n; i++) {
        if (a[i] > k) break;
        while(a[i] + b[j] > k)
            j--;
        ans = max(ans, i+j);
    }

    cout << ans;

    return 0;
}
