#include<map>
#include<list>
#include<queue>
#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>

#define imei(...)   "[ "<< #__VA_ARGS__ <<" ] "<< __VA_ARGS__

#define ull unsigned long long
#define ll long long
#define mp make_pair

using namespace std;

void solve(int t) {
    int n, m, k;
    cin >> n >> m >>k;

    int avg = n / k;
    if (m <= avg) {
        cout << m << endl;
        return;
    }
    m -= avg;
    int y = (m+k-2) / (k-1);

    cout << (avg-y) <<endl;
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
