// https://codeforces.com/gym/105588/problem/G

// It doesn't need to have the already built tree
// BFS runs on the fly and level can be tracked easily

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    ll a, b;
    cin >> a >> b;

    queue<tuple<ll, ll, int>> q;
    q.push({a, b, 0});
    ll ans = 0;

    while(!q.empty()) {
        auto [ca, cb, level] = q.front();
        q.pop();

        if(ca == 0 || cb == 0) {
            ans = level;
            break;
        }

        ll g = __gcd(ca, cb);
        level++;
        q.push({ca - g, cb, level});
        q.push({ca, cb - g, level});
    }  

    cout << ans + 1 << '\n';
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
