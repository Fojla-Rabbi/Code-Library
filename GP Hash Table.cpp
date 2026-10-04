#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long

void solve() {
    gp_hash_table<int, int> mp;
    // Then every operation is exactly like map
    // Only difference is it doesn't store keys as sorted
    // Faster than unordered_map
    // No collisions, absolutely fine
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
