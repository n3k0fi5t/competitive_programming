#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

vector<int> dp;

void solve(int t) {
    dp.clear();
    string s;
    cin >> s;
    int n = s.size(), prev = 0;
    ll ans = 0;

    dp.resize(n, 0);
    for (int i = 0; i < n; i++) {
        int v = s[i]=='-'?-1:1;
        dp[i] = prev + v;
        prev = dp[i];
    }

    ll pidx = 0;
    bool ok = false;
    int cur = 0;
    while(!ok) {
        ok = true;
        ans += pidx;
        for (int i = pidx; i < n; i++) {
                ans++;
                if (dp[i]+cur < 0) {
                    pidx = i;
                    ok = false;
                    break;
                }
        }
        cur++;
    }
    cout << ans<<endl;
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
