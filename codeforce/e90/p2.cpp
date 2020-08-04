#include<bits/stdc++.h>

#define ar array

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

map<string, bool> dp;

bool dfs(string& s) {
    int count = 0;
    int idx = 0;
    int n = s.size();
    int z = 0, o = 0;
    for (int i = 0; i< n; i++) {
        if (s[i] == '0')
            z++;
        else
            o++;
    }
    count = min(z, o);

    return count %2 !=0;

}

void solve(int t) {
    dp.clear();
    string s;
    cin >> s;

    if (dfs(s))
        cout << "DA"<<endl;
    else
        cout <<"NET"<<endl;
    return;
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
