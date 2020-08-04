#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

void solve(int t) {
    int n;
    cin >> n;
}

int main(int argc, char *argv[])
{
    int n, k, l = 1, r = 1;
    vector<int> a;

    cin >> n >> k;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r = max(r, a[i]);
    }

    while(l <= r) {
        int m = l + (r-l)/2;
        int need = 0;

        for (int &v : a)
            need += (v-1)/m;

        if (need > k)
            l = m + 1;
        else
            r = m - 1;

    }
    cout << l << endl;
    return 0;
}
