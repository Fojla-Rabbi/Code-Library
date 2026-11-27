#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    // clock() gives the cur number of clock tick or pulse
    clock_t st = clock();
    int n;
    cin >> n;

    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum << '\n';

    clock_t en = clock();
    cout << (double)(en - st) / CLOCKS_PER_SEC << "s\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
