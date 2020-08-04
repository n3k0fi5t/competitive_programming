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

vector<int> price;

void solve(int k) {
    int sum = 0;
    sort(price.begin(), price.end());

    for (int i = 0; i< k; i++)
        sum += price[i];

    cout << sum <<endl;
}
int main(int argc, char *argv[])
{
    int n, k;
    cin >>n >> k;
    for (int i = 0; i < n; i++) {
        int p;
        cin >>p;
        price.push_back(p);
    }

    solve(k);

    return 0;
}
