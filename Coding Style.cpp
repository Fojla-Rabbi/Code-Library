// Fixed

#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> seg(m);
    for(int i = 0; i < m; i++) {
        cin >> seg[i].first >> seg[i].second;
    }

    int q;
    cin >> q;

    vector<int> sq(q);
    for(int i = 0; i < q; i++) {
        cin >> sq[i];
    }

    ll low = 0, high = q - 1;
    int idx = q + 10;
    while(low <= high) {
        ll mid = (low + high) / 2;

        vector<int> v;
        for(int i = 0; i <= mid; i++) {
            v.push_back(sq[i]);
        }

        sort(v.begin(), v.end());

        bool flag = false;
        for(int i = 0; i < m; i++) {
            auto [l, r] = seg[i];

            auto it1 = lower_bound(v.begin(), v.end(), l);
            auto it2 = upper_bound(v.begin(), v.end(), r);

            if(it1 == v.end()) continue;

            int one_cnt = it2 - it1;
            int total_cnt = r - l + 1;
            int zero_cnt = total_cnt - one_cnt;

            if(one_cnt > zero_cnt) {
                flag = true;
                break;
            }
        }

        if(flag) {
            idx = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if(idx == q + 10) cout << "-1\n";
    else cout << idx + 1 << '\n';
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
