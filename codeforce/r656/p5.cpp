#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

vector<vector<int>> dir;
vector<pair<int, int>> undir;
bool ok;
int N;

vector<int> vis,act;

bool dfs(int u) {
    if (act[u]) return true;
    if (vis[u]) return false;
    vis[u] = true;
    for (int v : dir[u]) {
        if (!dfs(v))
            return false;
    }

    vis[u] = false;
    act[u] = true;
    return true;
}

bool check_cycle() {
    vis.clear();
    vis.resize(N, false);

    act.clear();
    act.resize(N, false);

    bool _ok = true;
    for (int i = 0; i < N; i++) {
        if (!dfs(i)) return false;
    }
    return true;
}

bool helper(int idx)
{
    if (idx == undir.size()) {
        ok = check_cycle();
        return ok;
    }

    int u = undir[idx].first, v = undir[idx].second;
    dir[u].push_back(v);
    //try u -> v;
    if (helper(idx+1))
        return true;
    dir[u].pop_back();

    //try v -> u;
    dir[v].push_back(u);
    if (helper(idx+1))
        return true;
    dir[v].pop_back();

    return false;
}

void solve(int t) {
    int n, m;
    cin >> n >> m;
    N = n;

    dir.clear();
    undir.clear();

    dir.resize(n);
    ok = false;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a>> b>> c;

        // dir
        if (a == 1) {
            dir[b-1].push_back(c-1);
        } else {
            undir.push_back({b-1, c-1});
        }
    }

    if(helper(0))
        undir.clear();

    if (undir.size() > 0) {
        cout<<"NO\n";
        return;
    }

    cout <<"YES\n";
    for (int i = 0; i < n; i++) {
        for (auto v : dir[i]) {
            cout << i+1 <<" "<<v+1<<endl;
        }
    }
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
