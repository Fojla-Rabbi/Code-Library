// Fixed

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n + 1), pref(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = (pref[i - 1] + a[i]) % k;
    }

    ll ans = 0;
    map<ll, o_set<int>> mp;
    mp[0].insert(0);
    for(int i = 1; i <= n; i++) {
        auto it = mp.find(pref[i]);
        if(it == mp.end()) {
            mp[pref[i]].insert(i);
            continue;
        }

        int idx = i - k;
        int cnt = mp[pref[i]].order_of_key(idx);
        ans += cnt;
        mp[pref[i]].insert(i);
    }

    cout << ans << '\n';
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
