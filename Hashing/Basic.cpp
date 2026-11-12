
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct DoubleHash {
    static const ll mod1 = 1e9 + 7;
    static const ll mod2 = 1e9 + 9;
    static const ll base1 = 31;
    static const ll base2 = 37;

    vector<ll> h1, h2, pw1, pw2;

    DoubleHash(const string &s) {
        int n = s.size();

        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);
        pw1.resize(n + 1, 1);
        pw2.resize(n + 1, 1);

        for(int i = 0; i < n; i++) {
            ll val = s[i] - 'a' + 1;

            h1[i + 1] = (h1[i] * base1 + val) % mod1;
            h2[i + 1] = (h2[i] * base2 + val) % mod2;

            pw1[i + 1] = (pw1[i] * base1) % mod1;
            pw2[i + 1] = (pw2[i] * base2) % mod2;
        }
    }

    pair<ll, ll> get_hash(int l, int r) {
        int len = r - l + 1;

        ll x = (h1[r + 1] - h1[l] * pw1[len] % mod1
                + mod1) % mod1;

        ll y = (h2[r + 1] - h2[l] * pw2[len] % mod2
                + mod2) % mod2;

        return {x, y};
    }
};

void solve() {
    string s;
    cin >> s;

    DoubleHash hs(s);

    int q;
    cin >> q;

    while(q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        if(r1 - l1 != r2 - l2) {
            cout << "NO\n";
            continue;
        }

        if(hs.get_hash(l1, r1) == hs.get_hash(l2, r2)) {
            cout << "YES\n";
        } 
        else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
