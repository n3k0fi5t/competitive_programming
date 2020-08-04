#include<map>
#include<list>
#include<queue>
#include<iostream>
#include<unordered_set>
#include<set>
#include<vector>

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

vector<int> num;
void solve(int t) {
    int n;
    cin >> n;
    num.clear();
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        num.push_back(v);
    }
    int mn = 0;
    int mn_idx = 0;
    int n_idx = 0;
    int mx = -1e9;
    int mx_idx = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += num[i];
        if (sum < mn) {
            mn_idx = i;
            mn = sum;
        }
        if (sum-mn > mx) {
            mx = sum-mn;
            mx_idx = i;
            n_idx = mn_idx+1;
        }
    }

    if (mx <= 0) {
        cout << 0 <<endl;
        return;
    }

    int m = -1e9;
    for (int i = n_idx; i <= mx_idx; i++)
        m = max(m, num[i]);

    if (m > 0)
        mx -= m;
    cout << mx<<endl;
}

int main(int argc, char *argv[])
{
    solve(0);
    return 0;
}
