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

void sieve(int n) {
    vector<bool> dp(n+1, true);
    for (int i = 2 ; i<= n; i++) {
        if (dp[i]) {
            for (int j = i*2; j <= n; j+=i)
                dp[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (dp[i])
            cout << i<<" ";
    }
    cout <<endl;
}

int main(int argc, char *argv[])
{
    sieve(300);

    return 0;
}
