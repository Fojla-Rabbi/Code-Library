
#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Hash {
    static const int p1 = 31;
    static const int p2 = 37;
    static const int mod1 = 1e9 + 7;
    static const int mod2 = 1e9 + 9;

    vector<pair<int, int>> h, p;

    Hash(string s) {
        int n = s.size();
        h.resize(n + 1);
        p.resize(n + 1);

        p[0] = {1, 1};

        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a' + 1;

            p[i + 1] = {
                1LL * p[i].first * p1 % mod1,
                1LL * p[i].second * p2 % mod2
            };

            h[i + 1] = {
                (1LL * h[i].first * p1 + x) % mod1,
                (1LL * h[i].second * p2 + x) % mod2
            };
        }
    }

    pair<int, int> get_hash(int l, int r) {
        // 0-indexed, inclusive
        int x = (h[r + 1].first -
                 1LL * h[l].first * p[r - l + 1].first % mod1
                 + mod1) % mod1;

        int y = (h[r + 1].second -
                 1LL * h[l].second * p[r - l + 1].second % mod2
                 + mod2) % mod2;

        return {x, y};
    }
};

void solve() {
    string s;
    cin >> s;

    Hash hs(s);

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
