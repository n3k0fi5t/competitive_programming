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

unordered_map<int, int> m;

int main(int argc, char *argv[])
{
    int n, q;
    ll sum = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        m[v]++;
        sum += v;
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a>>b;
        
        ll change = (b-a)*m[a];
        m[b] += m[a];
        m[a] = 0;
        sum += change;
        cout << sum<<endl;
    }

    return 0;
}
