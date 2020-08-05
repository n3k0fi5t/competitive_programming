#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

vector<int> a;
void solve(int t) {
    int n;
    int ans = 0;

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());
    for (int w = 1; w < 150; w++) {
        int l = 0, r = n - 1;
        int cnt = 0;
        while(l < r) {
            if (a[l] + a[r] == w) {
                l++;
                r--;
                cnt++;
            } else if (a[l] + a[r] < w) {
                l++;
            } else {
                r--;
            }
        }
        ans = max(ans, cnt);
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
