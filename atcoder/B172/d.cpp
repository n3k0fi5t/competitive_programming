#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

void solve(int t) {
    int n;
    cin >> n;
}

vector<int> c;

int main(int argc, char *argv[])
{
    int n;
    ll ans = 0;
    cin >> n;

    c.resize(n+1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j+=i) {
            c[j]++;
        }
    }

    for (ll i = 1; i <= n; i++) {
        ans += i * c[i];
    }

    cout << ans<<endl;

    return 0;
}
