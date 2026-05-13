#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

const int N = 2e5;

vector<array<int, 3>> g[N];
int depth[N], parent[N], sz[N], heavy[N], head[N], pos[N], arr[N], s[N];
int sgt[4 * N], lazy[4 * N];
int cur_pos = 1;
int n;

void push(int l, int r, int node){
    if(lazy[node] == 0)return;

    int mid = (l + r) / 2;
    sgt[2 * node] += lazy[node] * (mid - l + 1);
    sgt[2 * node + 1] += lazy[node] * (r - mid);
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    lazy[node] = 0;
}

void update(int node, int l, int r, int tl, int tr){
    if(l > tr || r < tl)return;
    if(l >= tl && r <= tr){
        sgt[node] += (r - l + 1);
        lazy[node]++;
        return;
    }
    push(l, r, node);

    int mid = (l + r) / 2;
    update(2 * node, l, mid, tl, tr);
    update(2 * node + 1, mid + 1, r, tl, tr);
    sgt[node] = sgt[2 * node] + sgt[2 * node + 1];
}

int query(int node, int l, int r, int tl, int tr){
    if(l > tr || r < tl)return 0;
    if(l >= tl && r <= tr){
        return sgt[node];
    }
    push(l, r, node);

    int mid = (l + r) / 2;
    return query(2 * node, l, mid, tl, tr) +
    query(2 * node + 1, mid + 1, r, tl, tr);
}


void dfs(int v, int d, int p, int si, int mi){
    parent[v] = p;
    depth[v] = d;
    sz[v] = 1;
    int max_sz = 0;
    s[v] = si;
    arr[v] = mi; 

    for(auto [u, sii, mii] : g[v]){
        if(u == p)continue;
        dfs(u, d + 1, v, sii, mii);
        sz[v] += sz[u];
        if(sz[u] > max_sz) {
            max_sz = sz[u];
            heavy[v] = u;
        }
    }
}

void dfs_hld(int v, int h){
    head[v] = h;
    pos[v] = cur_pos++;



    if(heavy[v] != -1){
        dfs_hld(heavy[v], h);
    }
    
    
    for(auto &[u, sii, vii] : g[v]){
        if(u == parent[v] || u == heavy[v])continue;
        dfs_hld(u, u);
    }
    
}

void update_path(int a, int b){
    while(head[a] != head[b]){
        if(depth[head[a]] < depth[head[b]]){
            swap(a, b);
        }
        update(1, 1, n, pos[head[a]], pos[a]);
        a = parent[head[a]];
    }
    if(depth[a] < depth[b])swap(a, b);

    update(1, 1, n, pos[b] + 1, pos[a]);
}

int query_path(int a, int b){
    int res = 0;
    while(head[a] != head[b]){
        if(depth[head[a]] < depth[head[b]]){
            swap(a, b);
        }
        res += query(1, 1, n, pos[head[a]], pos[a]);
        a = parent[head[a]];
    }
    if(depth[a] < depth[b])swap(a, b);

    res += query(1, 1, n, pos[b], pos[a]);
    return res;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) g[i].clear();
    memset(depth, 0, sizeof(depth));
    memset(parent, 0, sizeof(parent));
    memset(sz, 0, sizeof(sz));
    memset(heavy, -1, sizeof(heavy));
    memset(head, -1, sizeof(head));
    memset(pos, 0, sizeof(pos));
    memset(sgt, 0, sizeof(sgt));
    memset(lazy, 0, sizeof(lazy));
    
    cur_pos = 1;
    for(int i = 1; i < n; i++) {
        int a, b, si, vi;
        cin >> a >> b >> si >> vi;
        g[a].push_back({b, si, vi});
        g[b].push_back({a, si, vi});
    }
    dfs(1, 0, 1, 0, 0);
    dfs_hld(1, 1);
    for(int i = 1; i < n; i++) {
        update_path(i, i + 1);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        int c = query_path(i, i);
        int curr = min(s[i] * c, arr[i]);
        ans += curr;
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int tc = 1;
    cin >> tc;

    for(int i = 1;i <= tc;i++) {
        solve();
    }

    return 0;
}