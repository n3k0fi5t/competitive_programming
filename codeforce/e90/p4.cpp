#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

void solve(int t) {
    ll n, sum = 0;
    int ans = 0, cur = 0;
    cin >> n;
    vector<int> a, b, c;

    a.resize(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if ((i&1)^1)
            sum += a[i];
    }

    for (int i = 0; i+1 < n; i+=2) {
        cur = max(0, cur + a[i+1]-a[i]);
        ans = max(ans, cur);
    }

    cur = 0;
    for (int i = 1; i+1 < n; i+=2) {
        cur = max(0, cur + (a[i] - a[i+1]));
        ans = max(ans, cur);
    }
    cout << ans + sum<<endl;
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
