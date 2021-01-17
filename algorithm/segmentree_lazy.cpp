#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "

using namespace std;

const int nax = 1e4; // maximum input size
int node[nax*4+5];
int lazy[nax*4+5];
int n;

void push(int lo, int hi, int idx) {
    if (lazy[idx] == 0) return;
    node[idx] += lazy[idx] * (hi-lo+1);

    // push to childrens
    if (lo != hi) {
        lazy[2*idx+1] += lazy[idx];
        lazy[2*idx+2] += lazy[idx];
    }
    lazy[idx] = 0;
}

void upd(int us, int ue, int val, int lo = 0, int hi = -1, int idx = 0) {
    if (hi == -1) hi = n-1;
    push(lo, hi, idx);

    if (us > hi || ue < lo) return;

    // in range
    if (lo >= us && hi <= ue) {
        lazy[idx] += val;
        push(lo, hi, idx);
        return;
    }

    int mid = (lo + hi)/2;
    upd(us, ue, val, lo, mid, 2*idx+1);
    upd(us, ue, val, mid+1, hi, 2*idx+2);
    node[idx] = node[2*idx+1] + node[2*idx+2];
}

int query(int qs, int qe, int lo = 0, int hi = -1, int idx = 0) {
    if (hi == -1) hi = n-1;
    push(lo, hi, idx);

    if (hi < qs || lo > qe) return 0;
    if (lo >= qs && hi <= qe) return node[idx];
    int mid = (lo + hi)/2;
    return query(qs, qe, lo, mid, 2*idx+1) +
            query(qs, qe, mid+1, hi, 2*idx+2);
}

int main(int argc, char *argv[])
{
    n = 6;
    upd(0, 0, 0);
    upd(1, 1, 1);
    upd(2, 2, 2);
    upd(3, 3, 3);
    upd(4, 4, 4);
    upd(5, 5, 5);

    cout << query(1, 3)<<endl;
    cout << query(0, 5)<<endl;

    return 0;
}
