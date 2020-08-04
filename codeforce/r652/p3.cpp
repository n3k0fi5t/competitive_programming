#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define ar array
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

vector<ll> a, w;

void solve(int t) {
    int n, k;
    cin >>n >>k;
    a.clear();
    w.clear();

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a.push_back(v);
    }

    for (int i = 0; i < k; i++) {
        int v;
        cin >> v;
        w.push_back(v);
    }

    vector<ar<ll ,3>> mp(k);
    sort(a.begin(), a.end(), greater<int>());
    sort(w.begin(), w.end());

    for (int i = 0; i < k; i++) {
        mp[i][0] = w[i];
    }

    int cur = 0;
    int idx = -1;
    while(cur < n) {
        idx = (idx+1)%k;
        if (!mp[idx][0]) {
            continue;
        } else {
            mp[idx][1] = max(mp[idx][1], a[cur]);
            mp[idx][2] = min(mp[idx][2], a[cur]);
            mp[idx][0]--;
        }
        cur++;
    }
    ll ans = 0;
    for (int i = 0; i < k; i++) {
        ans += mp[i][1] + mp[i][2];
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
