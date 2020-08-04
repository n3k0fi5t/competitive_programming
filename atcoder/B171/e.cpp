#include<map>
#include<list>
#include<queue>
#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

vector<ll> val;

int main(int argc, char *argv[])
{
    int n;
    ll all = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        all ^= v;
        val.push_back(v);
    }

    for (int i = 0; i < n; i++) {
        all ^= val[i];
        cout << all <<" ";
        all ^= val[i];
    }

    return 0;
}
