#include<map>
#include<list>
#include<queue>
#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>
#include<cmath>

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

void solve(int t) {
    int n;
    cin >> n;
}

int main(int argc, char *argv[])
{
    int target, n;
    set<int> s;
    priority_queue<pair<int, int>> pq;
    cin >> target >> n;
    int mx = 1e9+5;
    int ans = target;

    if (!n) {
        cout << target <<endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        s.insert(val);
    }

    for (int i = -200; i <= 200; i++) {
        if (s.find(i) != s.end()) continue;
        if (abs(i-target) < mx) {
            ans = i;
            mx = abs(i-target);
        }
    }

    cout << ans<<endl;
    return 0;
}
