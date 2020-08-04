#include<map>
#include<list>
#include<queue>
#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>
#include<cmath>

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

int _h, _c, _t;
void solve(int a) {
    cin >> _h >> _c>>_t;
    double h = _h, c = _c, t= _t;
    int cnt = 1;
    int total = h, mn_cnt = 1;
    double mn = abs(h-t), cur = h;
    for (int i = 1; i < 30000; i++) {
        cnt++;
        if (i % 2) {
            total += c;
        } else {
            total += h;
        }
        cur =(double)total/cnt;
        if (abs(cur - t) < mn) {
            mn = abs(cur-t);
            mn_cnt = cnt;
        }
    }
    cout << mn_cnt<<endl;
}

int main(int argc, char *argv[])
{
    int d;
    cin >> d;
    while(d--) {
        solve(0);
    }

    return 0;
}
