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
    vector<int> rec;
    int n;
    cin >> n;

    rec.resize(n, 0);

    //R:1, W:0
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'R')
            rec[i] = 1;
    }

    int l = 0, r = n - 1, ans = 0;
    while(l < r) {
        while(l < r && rec[l])
            l++;
        while(l < r && !rec[r])
            r--;
        if (l < r)
            ans++;
        l++;
        r--;
    }

    cout << ans << "OK";

    return 0;
}
