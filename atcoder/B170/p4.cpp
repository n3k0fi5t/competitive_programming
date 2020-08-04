#include<map>
#include<list>
#include<queue>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<vector>
#include<cmath>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

vector<int> infant;
vector<int> rating;
unordered_map<int, priority_queue<int>> mp;

void solve(int idx, int to) {
    int from = infant[idx];

    if (!mp[from].empty() && rating[idx] == mp[from].top()) {
        mp[from].pop();
    }
    mp[to].push(rating[idx]);
    infant[idx] = to;

    int ans = 1e9;

    for (auto it : mp) {
        auto pq = it.second;
        if (!pq.empty() && pq.top() < ans)
            ans = pq.top();
    }

    cout << ans <<endl;
}

int main(int argc, char *argv[])
{
    int n, q;
    cin >> n >> q;
    infant.resize(n);
    rating.resize(n);

    for (int i = 0; i < n; i++) {
        int rate, k;
        cin >> rate>>k;
        rating[i] = rate;
        infant[i] = k;
        mp[k].push(rate);
    }

    for (int i = 0; i < q; i++) {
        int idx, to;
        cin >> idx >> to;
        solve(idx-1, to);
    }

    return 0;
}
