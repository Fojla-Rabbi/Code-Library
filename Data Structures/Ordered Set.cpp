#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve {
    o_set<int> se;
    se.insert(4);
    se.insert(2);
    se.insert(5);
    
    // sorted set se = [2, 4, 5]
    cout << se.order_of_key(5) << '\n'; // number of elements < 5
    cout << se.order_of_key(6) << '\n'; // number of elements < 6
    cout << (*se.find_by_order(1)) << '\n'; // 4
    // if you imagine this as a 0-indexed vector, what is se[1]?
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
