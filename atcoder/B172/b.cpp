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
    string s, t;
    cin >> s;
    cin >> t;

    int count = 0;

    for (int i = 0; i<s.size(); i++) {
        if (s[i] != t[i])
            count++;
    }

    cout << count<<endl;

    return 0;
}
