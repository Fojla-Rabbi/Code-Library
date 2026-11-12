
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct SegmentHash {
    static const ll mod1 = 1e9 + 7;
    static const ll mod2 = 1e9 + 9;
    static const ll base1 = 31;
    static const ll base2 = 37;

    struct Node {
        ll h1 = 0, h2 = 0;
        int len = 0;
    };

    int n;
    vector<Node> tree;
    vector<ll> pw1, pw2;

    SegmentHash(const string &s) {
        n = s.size();

        tree.resize(4 * n + 5);
        pw1.resize(n + 1, 1);
        pw2.resize(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            pw1[i] = pw1[i - 1] * base1 % mod1;
            pw2[i] = pw2[i - 1] * base2 % mod2;
        }

        if(n > 0) {
            build(1, 0, n - 1, s);
        }
    }

    Node merge(Node left, Node right) {
        Node res;

        res.len = left.len + right.len;

        res.h1 = (left.h1 * pw1[right.len] + right.h1) % mod1;
        res.h2 = (left.h2 * pw2[right.len] + right.h2) % mod2;

        return res;
    }

    void build(int node, int l, int r, const string &s) {
        if(l == r) {
            ll val = s[l] - 'a' + 1;
            tree[node] = {val, val, 1};
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int pos, char c) {
        if(l == r) {
            ll val = c - 'a' + 1;
            tree[node] = {val, val, 1};
            return;
        }

        int mid = (l + r) / 2;

        if(pos <= mid) {
            update(node * 2, l, mid, pos, c);
        } 
        else {
            update(node * 2 + 1, mid + 1, r, pos, c);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) {
            return {0, 0, 0};
        }

        if(ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }

    void update(int pos, char c) {
        update(1, 0, n - 1, pos, c);
    }

    pair<ll, ll> get_hash(int l, int r) {
        Node res = query(1, 0, n - 1, l, r);
        return {res.h1, res.h2};
    }
};

void solve() {
    string s;
    cin >> s;

    SegmentHash hs(s);

    int q;
    cin >> q;

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int pos;
            char c;
            cin >> pos >> c;

            hs.update(pos, c);
        } else if(type == 2) {
            int l1, r1, l2, r2;
            cin >> l1 >> r1 >> l2 >> r2;

            if(r1 - l1 != r2 - l2) {
                cout << "NO\n";
                continue;
            }

            if(hs.get_hash(l1, r1) == hs.get_hash(l2, r2)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
