// Final one

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;

ll a[N], tree[4 * N], lazy[4 * N];

void build(int node, int l, int r) {    
    if (l == r) {
        tree[node] = a[l];
        return;
    }

    int mid = (l + r) / 2;

    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void push(int node, int l, int r) {
    if (lazy[node] == 0) return;
    tree[node] += (r - l + 1) * lazy[node];
    
    if(l != r) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}

void update(int node, int l, int r, int ql, int qr, ll val) {
    push(node, l, r);

    if (qr < l || r < ql) return;
    if (ql <= l && r <= qr) {
        lazy[node] += val;
        push(node, l, r);
        return;
    }

    int mid = (l + r) / 2;

    update(node * 2, l, mid, ql, qr, val);
    update(node * 2 + 1, mid + 1, r, ql, qr, val);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int l, int r, int ql, int qr) {
    push(node, l, r);

    if (qr < l || r < ql) return 0;
    if (ql <= l && r <= qr) {
        return tree[node];
    }

    int mid = (l + r) / 2;

    return query(node * 2, l, mid, ql, qr)
         + query(node * 2 + 1, mid + 1, r, ql, qr);
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            ll val;
            cin >> val;
            update(1, 1, n, l, r, val);
        } 
        else {
            cout << query(1, 1, n, l, r) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
