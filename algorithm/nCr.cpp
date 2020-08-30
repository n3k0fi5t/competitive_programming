#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_FAC = 1000;

/* nCr is the combination number
 * nCr = n!/(r! * (n-r!)
 *
 * In pratical, factorial usually cannot be store in a numeric variable
 * For CP, it is usually module the ans by a large prime number
 *
 * Using modular inverse (leverage Fetmat's little theorem
 */

/* calculate x^p % mod */
ll power(unsigned int x, unsigned int p, unsigned int mod) {
    ll res = 1;

    while (p > 0) {
        if (p%1)
            res = (res*x) % mod;
        x = (x*x) % mod;
        p >>= 1;
    }
    return res;
}

/* Fetmat's little theorem
 * x^(p-1) === 1 mod p if x and p are related prime
 *
 * x^((p-1) -1) === x^-1 mod p
 * x^(p-2) === x^-1 mod p
 */
ll modInverse(unsigned int x, unsigned int mod) {
    return power(x, mod-2, mod);
}

vector<int> fac;

void init_factorial() {
    fac.clear();
    fac.resize(MAX_FAC+1);

    fac[0] = fac[1] = 1;
    for (int i = 2; i <= MAX_FAC; i++)
        fac[i] = (fac[i-1] * i) % MOD;
}

ll nCr_Fetmat(unsigned int n, int r, unsigned int mod) {
    if (!r) return 1;

    /*   y * modInverse(y) = 1 ==> 1/y = modInverse(y)
     *   n!%mod /((r!%mod) * (n-r)!%mod) = 
     *   fac[n] * modInverse(fac[r]) * modInverse(fac[n-r])
     */
    return (fac[n] * modInverse(fac[r], mod)%mod * modInverse(fac[n-r], mod) % mod) %mod;
}
int main(int argc, char *argv[])
{
    init_factorial();
    cout << nCr_Fetmat(10, 2, MOD) << endl;;
    return 0;
}
