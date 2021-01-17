#include<bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define imei(...)   "[ "<< #__VA_ARGS__ <<" = "<< __VA_ARGS__ <<" ] "
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

struct node {
    node *l, *r;
    int a, b;
    int mx, mn;

    node (int _a, int _b): a(_a), b(_b), l(nullptr), r(nullptr), mx(0), mn(0) {

    }
} *root;

void pull(node *n) {
    n->mx = max(n->l->mx, n->r->mx);
    n->mn = min(n->l->mn, n->r->mn);
}

void build(node *n, vector<int> &a) {
    if (n->a == n->b) {
        n->mx = n->mn = a[n->a];
        return;
    }
    int mid = (n->a + n->b)/2;
    n->l = new node(n->a, mid);
    n->r = new node(mid+1, n->b);
    build(n->l, a);
    build(n->r, a);
    pull(n);
}

pii query(node *n, int s, int e) {
    if (s > e) return mp(-1e9, 1e9);
    if (n->a > e || n->b < s) return mp(-1e9, 1e9);
    if (n->a >= s && n->b <= e) return mp(n->mx, n->mn);
    pii l = query(n->l, s, e);
    pii r = query(n->r, s, e);
    return mp(max(l.x, r.x),
              min(l.y, r.y));
}

#define Q(l, r) \
    q = query(root, l, r); \
    cout << "( "<<l<<", "<< r<<" ): "<<q.x<<" "<<q.y<<"\n";

int main(int argc, char *argv[])
{
    vector<int> in({
        1, 3, 8, -2, 5, 6, 2, 4, 9, 7, -3
    });
    int n = in.size();

    root = new node(0, n-1);
    build(root, in);

    for (int i = 0; i < n; i++)
        cout << in[i]<<" ";
    cout<<"\n";

    pii q;
    Q(0, 4);
    Q(2, 5);
    Q(1, 8);

    return 0;
}
