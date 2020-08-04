#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

void solve(int t) {
    ll a, b, c;
    cin >> a >>b>>c;
    ll ans1 = -1, ans2 = -1;

    // first
    if (a >= c) {
        ans1 = -1;
    } else {
        for (int i = 1; i <= 1000000000; i++) {
            if (a*i < ((i+b-1)/b)*c) {
                ans1 = i;
                break;
            }
        }
    }

    if (a * b <= c) {
        ans2 = -1;
    } else {
        for (ll i = b; i<=1000000000; i+=b) {
            if (a*i > i/b*c) {
                ans2 = i;
                break;
            }
        }
    }

    cout << ans1 <<" "<<ans2<<endl;
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
