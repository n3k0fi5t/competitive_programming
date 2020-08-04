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
    ll v = 0;
    int k, cnt = 0;
    cin >> k;

    int mx_iteration = 1e8;

    if (k%2==0) {
        cout <<"-1";
        return 0;
    }
    
    while(mx_iteration--) {
        cnt++;
        v = (v*10+7)%k;
        if (!v) {
            cout << cnt<<endl;
            return 0;
        }
    }
    cout << "-1";

    return 0;
}
