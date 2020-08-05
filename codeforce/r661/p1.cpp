#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

vector<int> a;

void solve(int t) {
    int n;
    cin >> n;

    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 1; i++) {
        if (a[i+1] - a[i] > 1) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
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
