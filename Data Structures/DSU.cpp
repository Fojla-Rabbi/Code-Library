#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int v) {
        if(parent[v] == v) {
            return v;
        }
        return parent[v] = find(parent[v]);
    } 

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            if(sz[a] < sz[b]) {
                swap(a, b);
            }
            parent[b] = a;
            sz[a] += sz[b];
        }
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int size(int v) {
        return sz[find(v)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
