#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

void solve(int t) {
    int n;
    cin >> n;
}

int main(int argc, char *argv[])
{
    ll n, d;
    int cnt = 0;

    cin >> n >> d;

    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (x*x + y*y <= d*d)
            cnt++;
    }

    cout << cnt;

    return 0;
}
