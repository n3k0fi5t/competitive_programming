#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

//#pragma GCC target("avx2")
//#pragma GCC optimization("unroll-loops")
//#pragma GCC optimize("O2")
//#pragma GCC optimize("O3")

#define FOR(i,a) for (int i=0;i<(a);++i)
#define FORD(i,a) for (int i=(a)-1;i>=0;i--)
#define FORT(i,a,b) for (int i=(a);i<=(b);++i)
#define FORTD(i,b,a) for (int i=(b);i>=(a);--i)
#define trav(i,v) for (auto i : v)
#define all(v) v.begin(),v.end()
#define ad push_back
#define fr first
#define sc second
#define mpr(a,b) make_pair(a,b)
#define pir pair<int,int>
#define make_unique(v) v.erase(unique(all(v)),v.end())
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define srng mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define y1 EsiHancagorcRepa

const int N=3e6+10; 
const ll MOD=998244353;

int qan[10];
int main(){

	fastio;
	int ttt;
	cin>>ttt;
	while(ttt--){
		string s;
		cin>>s;
		int n=s.length();
		memset(qan,0,sizeof qan);
		FOR(i,s.length())qan[s[i]-'0']++;
		int mn=INT_MAX;
		FOR(i,10){
			mn=min(mn,n-qan[i]);
		}
		FORT(i,0,9){
			FORT(j,0,9){
				if (i==j)continue;
				int tv=0;
				FOR(k,n){
					if (tv%2==0 && s[k]==(i+'0'))tv++;
					if (tv%2 && s[k]==(j+'0'))tv++;
				}
				if (tv%2)tv--;
				mn=min(mn,n-tv);
			}
		}
		cout<<mn<<endl;
	}
	return 0;
}	
/*
1
3
aab
bcc
*/
