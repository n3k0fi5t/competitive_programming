#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

int dc(string& p, char c, int l, int r)
{
    int lcnt = 0, rcnt = 0;
    if (l == r) return p[l] == c?0:1;
    int m = (l+r+1)/2;

    //lhs
    for (int i = l; i < m; i++) {
        if (p[i] != c)
            lcnt++;
    }

    //rhs
    for (int i = m; i <= r; i++) {
        if (p[i] != c)
            rcnt++;
    }

    return min(lcnt+dc(p, c+1, m, r), rcnt+dc(p, c+1, l, m-1));
}

void solve(int t) {
    string s;
    int n;
    cin >> n;
    cin >> s;

    cout << s<<endl;
    cout << dc(s, 'a', 0, n-1) <<endl;
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
