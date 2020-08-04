#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

int ans;
bool ok;
void helper(vector<int>& p) {
    int mx = INT_MIN;
    int idx = -1;
    for (int i = 0; i < p.size(); i++) {
        if (p[i] > mx) {
            idx = i;
            mx = p[i];
        }
    }

    int prev = mx;
    for (int i = idx+1; i < p.size(); i++) {
        if (p[i] > prev) {
            ans += idx+1;
            p.erase(p.begin(), p.begin()+idx+1);
            helper(p);
            break;
        }
        prev = p[i];
    }
    if (ok)
        return;

    prev = mx;
    for (int i = idx-1; i > -1; i--) {
        if (p[i] > prev) {
            ans += i+1;
            ok = true;
            break;
        }
        prev = p[i];
    }

    ok = true;
}

vector<int> b;
void solve(int t) {
    int n;
    cin >> n;

    b.resize(n);

    for (int i = 0; i < n; i++)
        cin >> b[i];

    ans = 0;
    ok = false;

    helper(b);

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
