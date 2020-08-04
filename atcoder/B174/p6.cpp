#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

class BIT {
public:
        BIT(int _n): n(_n) {
            bit.clear();
            bit.resize(n+1);
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
vector<tuple<int, int, int>> queries;
vector<int> occurence;
vector<int> c;
vector<int> ans;

int main(int argc, char *argv[])
{
    cin >> n >> q;
    occurence.resize(MAX_N, -1);
    c.resize(MAX_N);
    queries.resize(q);
    ans.resize(q);

    BIT bit(MAX_N);

    for (int i = 0; i < n; i++) {
        cin >> c[i+1];
        bit.add(i+1, 1);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[i] = tuple<int, int ,int>(l, r, i);
    }

    sort(queries.begin(), queries.end(), [&](auto& p1, auto& p2) {
            if (get<1>(p1) == get<1>(p2)) return get<0>(p1) < get<1>(p2);
            return get<1>(p1) < get<1>(p2);
        });

    int cur = 1;
    for (int i = 0; i < q; i++) {
        int s = get<0>(queries[i]);
        int e = get<1>(queries[i]);
        for(; cur <= e; cur++) {
            if (occurence[c[cur]] != -1)
                bit.add(occurence[c[cur]], -1);
            occurence[c[cur]] = cur;
            bit.add(cur, 1);
        }
        cur--;

        int query_idx = get<2>(queries[i]);
        ans[query_idx] = bit.query(s, e);
    }

    for (auto &a : ans)
        cout << a << endl;

    return 0;
}
