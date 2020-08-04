#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

set<int> s;
void solve(int t) {
    int n;
    cin >> n;
    s.clear();

    for (int i = 0; i < 2*n; i++) {
        int tmp;
        cin >> tmp;
        if(!s.count(tmp))
            cout << tmp <<" ";
        s.insert(tmp);
    }

    cout << "\n";
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
