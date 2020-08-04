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

vector<vector<int>> sq;
int price;
int r, c, x, y;

void dfs(int i, int j) {
    if (2*x<y) {
        price += x;
    } else {
        if (j+1 < c && sq[i][j+1] == 1) {
            sq[i][j+1] = 0;
            price += y;
        } else {
            price += x;
        }
    }
}

void solve(int t) {
    cin >> r >> c >> x >> y;
    sq.clear();
    sq.resize(r, vector<int>(c, 0));
    price = 0;

    for (int i = 0; i < r; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < c; j++) {
            if (s[j] == '.') sq[i][j] = 1;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sq[i][j] == 1) {
                dfs(i, j);
            }
        }
    }
    cout << price << endl;
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
