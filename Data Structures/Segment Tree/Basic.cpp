// Final one

#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct SegTree {
    struct Node {
        int gcd = 0;
        int mn = INT_MAX;
        int cnt = 0;
    };

    int n;
    vector<Node> tree;

    SegTree(const vector<int> &a) {
        n = a.size();
        tree.resize(4 * n + 5);

        if(n > 0) {
            build(1, 0, n - 1, a);
        }
    }

    Node merge(Node left, Node right) {
        Node res;

        res.gcd = __gcd(left.gcd, right.gcd);
        res.mn = min(left.mn, right.mn);

        if(left.mn == right.mn) {
            res.cnt = left.cnt + right.cnt;
        }
        else if(left.mn < right.mn) {
            res.cnt = left.cnt;
        }
        else {
            res.cnt = right.cnt;
        }

        return res;
    }

    void build(int node, int l, int r, const vector<int> &a) {
        if(l == r) {
            tree[node] = {a[l], a[l], 1};
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, a);
        build(node * 2 + 1, mid + 1, r, a);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, int val) {
        if(l == r) {
            tree[node] = {val, val, 1};
            return;
        }

        int mid = (l + r) / 2;

        if(pos <= mid) {
            update(node * 2, l, mid, pos, val);
        }
        else {
            update(node * 2 + 1, mid + 1, r, pos, val);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) {
            return {0, INT_MAX, 0};
        }

        if(ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }

    Node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SegTree st(a);

    // Update position 2 to value 10
    st.update(2, 10);

    // Query range [1, 4]
    auto res = st.query(1, 4);

    cout << res.gcd << '\n';
    cout << res.mn << '\n';
    cout << res.cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
