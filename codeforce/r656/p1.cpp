#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

#define fail \
    do { cout <<"NO\n"; return;} while(0);
#define yes(a, b, c) \
    do { cout << "YES\n" << a << " "<< b<<" "<<c<<endl; return ;} while(0);

void solve(int t) {
    int x, y, z;
    cin >> x >> y >> z;
    
    if (x == y) { // max a
        if (z > x) fail;
        yes(x, z, z);
    } else if ( y == z) { // max c
        if (x > y) fail;
        yes(y, x, x);
    } else if ( x == z) { // max b
        if (y > z) fail;
        yes(x, y, y);
    } else {
        cout << "NO\n";
        return;
    }

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
