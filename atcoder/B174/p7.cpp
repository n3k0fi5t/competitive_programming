#include <bits/stdc++.h>
using namespace std;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()
 
#define MOO(i, a, b) for(int i=a; i<b; i++)
#define M00(i, a) for(int i=0; i<a; i++)
#define MOOd(i,a,b) for(int i = (b)-1; i >= a; i--)
#define M00d(i,a) for(int i = (a)-1; i>=0; i--)
 
#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _ << " _ " <<
 
template<class T> bool ckmin(T& a, const T& b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T& a, const T& b) {return a < b ? a = b, 1 : 0;}
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
 
template<int sz> struct BIT {
    int b[sz+1];
    BIT() {
        M00(i, sz+1) b[i] = 0;
    }
    void add(int k, int val) {
        k++;
        for(; k <= sz; k+=(k&-k)) b[k] += val;
    }
    int psum(int ind) {
        int ans = 0;
        ind++;
        for(; ind>0; ind-=(ind&-ind)) ans+=b[ind];
        return ans;
    }
    int sum(int l, int r) {
        return psum(r) - psum(l-1);
    }
};
 
const int MAX_N = 500050;
int n, q;
int arr[MAX_N];
pi ori[MAX_N];
pi queries[MAX_N];
int idx[MAX_N];
BIT<MAX_N> b;
map<pi, int> ans;
 
bool sortSecond(pi p1, pi p2) {
    return p1.s < p2.s;
}
 
int main() { FAST
    cin >> n >> q;
    M00(i, n) {
        cin >> arr[i];
        arr[i]--;
    }
    M00(i, q) {
        cin >> queries[i].f >> queries[i].s;
        queries[i].f--;
        queries[i].s--;
        ori[i] = queries[i];
    }
    sort(queries, queries+q, sortSecond);
    int cur = 0;
    M00(i, n) idx[i] = -1;
    M00(i, q) {
        cout << queries[i].f <<" " << queries[i].s<<endl;
        for(; cur <= queries[i].s; cur++) {
            if(idx[arr[cur]] != -1) {
                b.add(idx[arr[cur]], -1);
            }
            idx[arr[cur]] = cur;
            b.add(cur, 1);
        }
        cur--;
        ans[queries[i]] = b.sum(queries[i].f, queries[i].s);
    }
    M00(i, q) cout << ans[ori[i]] << "\n";
}
