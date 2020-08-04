#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

class BIT {
public:
        BIT(int _n): n(_n) {
            bit.clear();
            bit.resize(n+1, 0);
        }

        void add(int x, int v) {
            while(x <= n) {
                bit[x]+=v;
                x += x&-x;
            }
        }

        int sum(int x) {
            int s = 0;
            while(x > 0) {
                s += bit[x];
                x -= x&-x;
            }
            return s;
        }

        int query(int l, int r) {
            return sum(r) - sum(l-1);
        }
private:
    int n;
    vector<int> bit;
};

const int MAX_N = 5e5+50;
int n, q;
vector<pair<int, int>> queries, ori;
map<pair<int, int>, int> mp;
vector<int> occurence;
vector<int> c;
vector<int> ans;

int main(int argc, char *argv[])
{
    cin >> n >> q;
    occurence.resize(MAX_N, -1);
    c.resize(MAX_N);
    queries.resize(q);
    ori.resize(q);

    BIT bit(MAX_N);

    for (int i = 0; i < n; i++) {
        cin >> c[i+1];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = {l, r};
        ori[i] = queries[i];
    }

    sort(queries.begin(), queries.end(), [&](auto& p1, auto& p2) {
            if (p1.second == p2.second) return p1.first < p2.first;
            return p1.second < p2.second;
        });

    int cur = 1;
    for (int i = 0; i < q; i++) {
        int l = queries[i].first;
        int r = queries[i].second;
        for (; cur <= r; cur++) {
            if (occurence[c[cur]] != -1)
                bit.add(occurence[c[cur]], -1);
            occurence[c[cur]] = cur;
            bit.add(cur, 1);
        }
        cur--;
        mp[make_pair(l, r)] = bit.query(l, r);
    }

    for (int i = 0; i < q; i++)
        cout << mp[ori[i]]<<endl;

    return 0;
}
