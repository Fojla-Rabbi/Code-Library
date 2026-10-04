#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, int> mp;
    bool one_odd = true;

    for(int i = 1; i <= n; i++) {
        if(i % 2 == 0) {
            mp[a[i]] = 0;
            if(a[i] == 1) {
                one_odd = false;
            }
        }
        else mp[a[i]] = 1;
    }

    if(n % 2 != 0 && !one_odd) {
        cout << "NO\n";
        return;
    }

    vector<int> first, last;
    for(int i = 1; i <= n - 2; i++) {
        if(mp[i] == mp[i + 1]) {
            int prev = i, cur = i + 2;
            while(cur < n) {
                if(mp[cur] == mp[prev]) {
                    last.push_back(cur);
                    cur++;
                }
                else {
                    first.push_back(cur);
                    prev = cur;
                    cur++;
                } 
            }

            break;
        }
    }
    
    reverse(last.begin(), last.end());

    vector<int> final = first;
    final.push_back(n);

    for(int i = 0; i < last.size(); i++) {
        final.push_back(last[i]);
    }

    for(int i = 1; i < final.size(); i++) {
        if(mp[final[i]] == mp[final[i - 1]]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
