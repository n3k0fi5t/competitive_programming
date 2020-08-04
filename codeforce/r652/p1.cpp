#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

void solve(int t) {
    ll n;
    ll a, b;
    cin >> n;

    a = (n-2) * 180;
    b = a/n;
    
    if ( (n%4)!= 0)
        cout << "NO\n";
    else
        cout << "YES\n";

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
