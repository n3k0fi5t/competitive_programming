#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define mp make_pair
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

const int M = 1e9+9;
/* prime number larger than input set size
 * for example, we only have lowercase of English letter ==> 26
 * we could choose prime 29, 31, ...
 * */
const int p = 31;

/* string hash
 * hash(s) = sum(s[0] + s[1]*p + s[2]*p^2 + ... + s[n-1]*p^(n-1)) % M;
 * */

void search(string T, string P)
{
    int n = T.size(), m = P.size();
    if (!n || !p) return;

    vector<long long> ht(n+1, 0);
    vector<long long> p_pow(n+1, 1);

    // calculate power of p
    for (int i = 1; i <= n; i++)
        p_pow[i] = (p_pow[i-1]*p) % M;

    // calculate hash of pattern
    long long hp = 0;
    for (int i = 1; i <= m; i++)
        hp = (hp + (P[i-1]-'A'+1) * p_pow[i-1]) % M;

    //calculate hash of text
    for (int i = 1; i <= n; i++)
        ht[i] = (ht[i-1] + (T[i-1]-'A'+1) * p_pow[i-1]) % M;
    
    // rolling hash for finding all occurence of string P in string T
    for (int i = 0; i + m <= n; i++) {
        long long cur_h = (ht[i+m] - ht[i] + M) % M; // ht[i+m] may less than ht[i], so we add M to avoid result being negative
        if (cur_h == (hp * p_pow[i]) % M)
            cout << i <<" "<< T.substr(i, m)<<endl;
    }

}

void search2(string T, string P) {
    int n = T.size(), m = P.size();
    long long hp = 0;
    long long ht = 0;
    long long pp = 1;

    if (!n || !m) return;

    for (int i = 0 ; i < m; i++) {
        hp = (hp * p + (P[i] - 'A' + 1)) % M;
        ht = (ht * p + (T[i] - 'A' + 1)) % M;
    }

    if (hp == ht)
        cout << "0 "<<P<<endl;

    for (int i = 0; i < m; i++)
        pp = (pp * p) %M;

    /*
     * ht[0:m]  = (t[0]*p^m-1 + t[1]*p^m-2 + t[2]*p^m-3 + ... + t[m-1])%M = ht
     *          = (t[0]*p^m-1)%M + (t[1]*p^m-2 + t[2]*p^m-3 + ... + t[m-1])%M
     * ht[1:m+1]=              + t[1] * p^m-1 + t[2] * p^m-2 + ... + t[m-1]*p
     * + t[m]   = 
     *
     */

    for (int i = 1; i + m <= n; i++) {
        ht = ((ht*p) - pp*(T[i-1]-'A'+1) %M  + M  + (T[i-1+m]-'A'+1)) %M;
        if (ht == hp)
            cout << i<<" "<<T.substr(i, m)<<endl;
    }

}

int main(int argc, char *argv[])
{
    string T = "AABAACAADAABAABA";
    string P = "AABA";

    search(T, P);
    search2(T, P);
    return 0;
}
