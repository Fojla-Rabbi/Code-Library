#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
  
    vector<pair<int, int>> vp(n);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vp[i] = {a, b};
    }
  
    // Sorting with custom comparator(on the basis of second)
    // Ascending order
    sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
        // true --> keeps them as they are
        // false --> makes change 
        // Never use <= never
    });
    
    for(int i = 0; i < n; i++) {
        cout << vp[i].second << " ";
    }
   
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
