#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

vector<int> n1, n2;

void solve(int t) {
    string s1; 
    int n;
    cin >> n;
    cin >> s1;
    while(s1.size()) {
        n1.push_back(s1.back()-'0');
        s1.pop_back();
    }
    reverse(n1.begin(), n1.end());

    int cur = 0;
    int idx;

    // start with 0000000
    while(cur < n && !n1[cur]) {
        cout <<"0";
        cur++;
    }

    idx = cur - 1;
    for (int i = cur; i<n;i++) {
        if (!n1[i])
            idx = i;
    }

    // if there have  zero behind the 1, all 1 could be eliminated and left a 0
    if (idx != cur-1) {
        cout <<"0";
    }

    for (int i = idx+1; i < n; i++)
        cout <<"1";

    cout <<"\n";
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
