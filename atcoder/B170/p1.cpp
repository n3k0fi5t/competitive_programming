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

int main(int argc, char *argv[])
{
    int a, idx = 1;
    while(idx <= 5) {
        cin >> a;
        if (!a)
            break;
        idx++;
    }

    cout << idx << endl;

    return 0;
}
