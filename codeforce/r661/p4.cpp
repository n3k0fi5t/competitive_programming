#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

string s;
int n;

set<int> zeros, ones;
void solve(int t) {
    vector<int> ans;
    int group = 0;
    int zi = 0, oi = 0;

    cin >> n;
    cin >> s;
    ans.resize(n);
    zeros.clear();
    ones.clear();

    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            zeros.insert(i);
        else
            ones.insert(i);
    }

    while(zeros.size() || ones.size()) {
        if (!zeros.size()) {
            for (auto it : ones) {
                ans[it] = group;
                group++;
            }
            break;
        } else if (!ones.size()) {
            for (auto it : zeros) {
                ans[it] = group;
                group++;
            }
            break;
        } else {
            int idx = -1;
            int gozero = *zeros.begin() < *ones.begin();
            while(true) {
                set<int>::iterator it;
                if (gozero) {
                    it = zeros.upper_bound(idx);
                    if (it == zeros.end()) break;
                    idx = *it;
                    zeros.erase(it);
                } else {
                    it = ones.upper_bound(idx);
                    if (it == ones.end()) break;
                    idx = *it;
                    ones.erase(it);
                }
                gozero = !gozero;
                ans[idx] = group;
            }
        }
        group++;
    }

    cout << group<<endl;
    for (auto &c : ans)
        cout << c+1 << " ";
    cout << endl;
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
