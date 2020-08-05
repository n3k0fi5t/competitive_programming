#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;
const ll MAX_N = 1e5+10;
// u->(v, w)
vector<vector<pair<ll, ll>>> adj;
//weight, number of leafs
multiset<vector<ll>> refine;
vector<bool> vis;
ll s;

ll dfs(ll idx, ll w) {
    ll cnt = 0;
    vis[idx] = 1;

    for (auto &p : adj[idx]) {
        if (!vis[p.first])
            cnt += dfs(p.first, p.second);
    }
    
    if (!cnt) cnt++;
    refine.insert({(w-w/2)*cnt, w, cnt});
    s+= w*cnt;
    return cnt;
}

void solve(ll t) {
    ll n, S;
    cin >> n >> S;
    adj.clear();
    refine.clear();
    vis.clear();

    adj.resize(n);
    for (ll i = 0; i < n-1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vis.resize(n, false);
    dfs(0, 0);

    ll ans = 0;
    for (; s > S; ans++) {
        auto v = *refine.rbegin();
        refine.erase(refine.find(v));
        s -= v[0];
        v[1] >>= 1;
        v[0] = (v[1] - v[1]/2)*v[2];
        refine.insert(v);
    }
    cout << ans<<endl;

    //clean up
    ans = s = 0;
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
