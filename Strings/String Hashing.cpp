// Final one

#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct Hash {
    static const int mod1 = 1e9 + 7;
    static const int mod2 = 998244353;
    static const int p1 = 31;
    static const int p2 = 59;

    vector<pair<int, int>> h, pw;

    Hash(const string& s) {
        int n = s.size();
        h.resize(n);
        pw.resize(n);
        
        pw[0] = {1, 1};
        h[0] = {s[0] - 'a' + 1, s[0] - 'a' + 1};

        for (int i = 1; i < n; i++) {
            int val = s[i] - 'a' + 1;

            pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
            pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;

            h[i].first = (1LL * h[i - 1].first * p1 + val) % mod1;
            h[i].second = (1LL * h[i - 1].second * p2 + val) % mod2;    
        }
    }

    pair<int, int> get_hash(int l, int r) {
        // 0-indexed, inclusive
        if(l == 0) return h[r];

        int x = (h[r].first -
                 1LL * h[l - 1].first * pw[r - l + 1].first % mod1
                 + mod1) % mod1;

        int y = (h[r].second -
                 1LL * h[l - 1].second * pw[r - l + 1].second % mod2
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

        l1--; 
        r1--; 
        l2--; 
        r2--;

        if(r1 - l1 != r2 - l2) {
            cout << "NO\n";
            continue;
        }

        if(hs.get_hash(l1, r1) == hs.get_hash(l2, r2)) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
