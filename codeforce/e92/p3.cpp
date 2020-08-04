#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

void solve(int t) {
    int n;
    string s;
    vector<int> qan(10, 0);
    int ans = 1e9;

    cin >> s;
    n = (int)s.size();

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int cur = 0;
            int step = 0;
            int cnt = 0;
            while(cur < n) {
                if (cnt % 2 == 0 && s[cur] - '0' == i) cnt++;
                else if (cnt % 2 && s[cur]-'0' == j) cnt++;
                cur++;
            }
            if (cnt % 2 && i != j)
                cnt--;
            ans = min(ans, n-cnt);
        }
    }
    cout <<ans <<"\n";
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
