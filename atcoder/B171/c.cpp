#include<map>
#include<list>
#include<queue>
#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

void solve(int l, long long n) {
    vector<long long> tbl(1, 1);
    vector<char> cs;

    for (int i =0 ;i < 26; i++)
        cs.push_back(i+'a');

    for (int i = 0; i < l; i++)
        tbl.push_back(tbl.back()*26);

    while(l > 0) {
        int idx = (n - 1)/tbl[l-1];
        cout << cs[idx];
        n -= idx * tbl[l-1];
        l--;
    }
}

int main(int argc, char *argv[])
{
    long long n;
    cin >> n;

    long long count = 0;
    long long val = 1;
    int len = 1;

    for (;;) {
        val *= 26;
        if (count + val >= n)
            break;
        count += val;
        len++;
    }

    solve(len, n-count);

    return 0;
}
