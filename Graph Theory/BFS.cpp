#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2e5 + 5;
vector<int> adj[N];
bool vis[N];
int dist[N];

void solve() {
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int src;
    cin >> src;

    queue<int> q;
    q.push(src);
    vis[src] = true;
    dist[src] = 0;
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v : adj[u]) {
            if(!vis[v]) {
                // perfect order
                q.push(v);
                vis[v] = true;
                dist[v] = dist[u] + 1;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
