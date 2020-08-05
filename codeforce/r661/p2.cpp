#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;
vector<ll> a, b;
vector<pair<ll, ll>> c;
void solve(ll t) {
    ll n;
    ll ans = 0;
    ll min_a = 1e9, min_b = 1e9;

    cin >> n;
    c.resize(n);

    for (ll i = 0; i < n; i++) {
        cin >> c[i].first;
        min_a = min(min_a, c[i].first);
    }
    for (ll i = 0; i < n; i++) {
        cin >> c[i].second;
        min_b = min(min_b, c[i].second);
    }

    sort(c.begin(), c.end());

    for (ll i = 0; i < n; i++) {
        ll diff_a = c[i].first - min_a;
        ll diff_b = c[i].second - min_b;
        ans += max(diff_a, diff_b);
    }

    cout << ans<<endl;
}

int main(int argc, char *argv[])
{
    ll d;
    cin >> d;
    ll t = 0;
    while(d--) {
        solve(++t);
    }

    return 0;
}
