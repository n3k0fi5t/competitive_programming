#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

ll gcd(ll a, ll b) {
    while(b) {
        ll c = a % b;
        a = b;
        b = c;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a*b)/gcd(a,b);
}

void solve(ll t) {
    ll l, r;
    ll lhs, rhs;
    cin >> l >> r;

    lhs = l;
    rhs = r;
    while(lhs <= rhs) {
        int m = lhs + (rhs-lhs)/2;
        if (l <= 2*m && r >= 2*m) {
            cout << m <<" "<<2*m<<endl;
            return;
        }
        rhs = m-1;
    }
    cout << "-1 -1\n";
}

int main(int argc, char *argv[])
{
    ll d;
    cin >> d;
    ll t = 0;
    while(d--) {
        solve(++t);
    }

    return 0;
}
