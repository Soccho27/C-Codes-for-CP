/*
    shohag bhhai template theke edit kora, kichu tips, dfs call kore sob initialize korte hobe
    jodi buildtree er modhe empty vector pass kora hoi taile tokhon e return korte hobe
    

    mainly virtual tree jevabe ber kore seta hoche important vertex gulo sort kore then pashapashi
    LCA ber kore
*/ 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mmst(i, a) memset(i,a,sizeof(i))
#define all(i) i.begin(),i.end()
#define SS " "
#define ddd cout<<"D"<<nl;
#define pp(x) cout<<x<<nl
const char nl = '\n';

const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int inf = 1e18;

const int N = 3e5 + 9;

vector<int> g[N];
int par[N][25], dep[N], sz[N], st[N], en[N], T, c[N];
set<int> cutie;
void dfs(int u, int pre) {
  par[u][0] = pre;
  dep[u] = dep[pre] + 1;
  sz[u] = 1;
  st[u] = ++T;
  for (int i = 1; i <= 18; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  for (auto v : g[u]) {
    if (v == pre) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
  en[u] = T;
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = 18; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  if (u == v) return u;
  for (int k = 18; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
  return par[u][0];
}
int kth(int u, int k) {
  for (int i = 0; i <= 18; i++) if (k & (1 << i)) u = par[u][i];
  return u;
}
int dist(int u, int v) {
  int lc = lca(u, v);
  return dep[u] + dep[v] - 2 * dep[lc];
}
int isanc(int u, int v) {
  return (st[u] <= st[v]) && (en[v] <= en[u]);
}
vector<int> t[N];
// given specific nodes, construct a compressed directed tree with these vertices(if needed some other nodes included)
// returns the nodes of the tree
// nodes.front() is the root
// t[] is the specific tree
void buildtree(vector<int> v, int curClr) {
    if(v.size() == 0)return;
    // sort by entry time
    sort(v.begin(), v.end(), [](int x, int y) {
        return st[x] < st[y];
    });
    // finding all the ancestors, there are few of them
    int s = v.size();
    for (int i = 0; i < s - 1; i++) {
        int lc = lca(v[i], v[i + 1]);


        // MAIN LOGIC STARTS HERE
        if(c[lc] != curClr){
            if(c[lc])cutie.insert(lc);
            else c[lc] = curClr;
        }




        v.push_back(lc);
    }
    return;
}

void Fdfs(int node, int par, int clr){
    if(c[node] == 0)c[node] = clr;
    for(auto it: g[node]){
        if(it == par)continue;
        Fdfs(it, node, c[node]);
    }
}

void resetAll(int n) {
    T = 0;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        st[i] = en[i] = c[i] = dep[i] = 0;
        for (int j = 0; j < 25; j++)par[i][j] = 0;
    }
    cutie.clear();
}

void solve()
{
    int n,k;cin>>n>>k;
    resetAll(n);
    int w[n + 1];for(int i = 1; i <= n; i++)cin>>w[i];
    vector<int> clrAdj[k + 1];
    for(int i = 1; i <= n; i++){int x;cin>>x;c[i] = x;clrAdj[x].push_back(i);}
    for(int i = 1; i < n; i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);

    for(int i = 1; i <= k; i++){
        buildtree(clrAdj[i], i);    // main logic is in this function
    }
    
    int root = -1;
    for(int i = 1; i <= n; i++)if(c[i] != 0){root = i;break;}
    if(root == -1)root = 1, c[1] = 1;
    Fdfs(root, -1, c[root]);

    int ans = 0;
    for(auto it: cutie){
        ans += w[it];
    }
    
    cout<<ans<<nl;
    for(int i = 1; i <= n; i++)cout<<c[i]<<" ";cout<<nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        // cout<<"Case "<<tc<<": ";
        solve();
    }
    return 0;
}



// eta diye AC koraini konota, eta just youtube video theke dekha, pastebin a details ache
const int N = 100005;
const int LOGN = 20;
vector<int> g[N];
vector<int> adjacency_vt[N];
int tin[N], tout[N], timer;
int up[N][LOGN];
int depth[N];
bool important[N];
int subtree_count[N];
long long ans;
int total_count;
void dfs(int u, int p, int d) {
    tin[u] = ++timer;
    depth[u] = d;
    up[u][0] = p;
    for (int i = 1; i < LOGN; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }
    for (int v : g[u]) {
        if (v != p) {
            dfs(v, u, d + 1);
        }
    }
    tout[u] = ++timer;
}
bool upper(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}
int lca(int u, int v) {
    if (upper(u, v)) return u;
    if (upper(v, u)) return v;
    for (int i = LOGN - 1; i >= 0; --i) {
        if (!upper(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}
bool cmp(int a, int b) {
    return tin[a] < tin[b];
}
int build_virtual_tree(vector<int>& vert) {
    sort(vert.begin(), vert.end(), cmp);
    int k = vert.size();
    for (int i = 0; i < k - 1; ++i) {
        vert.push_back(lca(vert[i], vert[i + 1]));
    }
    sort(vert.begin(), vert.end(), cmp);
    vert.erase(unique(vert.begin(), vert.end()), vert.end());
    for (int u : vert) {
        adjacency_vt[u].clear();
    }
    vector<int> stack_v;
    stack_v.push_back(vert[0]);
    for (int i = 1; i < vert.size(); ++i) {
        int u = vert[i];
        while (stack_v.size() >= 2 && !upper(stack_v.back(), u)) {
            adjacency_vt[stack_v[stack_v.size() - 2]].push_back(stack_v.back());
            stack_v.pop_back();
        }
        stack_v.push_back(u);
    }
    while (stack_v.size() >= 2) {
        adjacency_vt[stack_v[stack_v.size() - 2]].push_back(stack_v.back());
        stack_v.pop_back();
    }
    return stack_v[0];
}
void solve(int u, int p) {
    subtree_count[u] = important[u];
    for (int v : adjacency_vt[u]) {
        solve(v, u);
        subtree_count[u] += subtree_count[v];
    }
    if (p != -1) {
        int w = depth[u] - depth[p];
        ans += (long long)w * subtree_count[u] * (total_count - subtree_count[u]);
    }
}
int main() {
    int n;cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    timer = 0;
    dfs(1, 1, 0);
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        vector<int> vert(k);
        for (int i = 0; i < k; ++i) {
            cin >> vert[i];
            important[vert[i]] = true;
        }
        total_count = k;
        ans = 0;
        int vt_root = build_virtual_tree(vert);
        solve(vt_root, -1);
        cout << ans << "\n";
        for (int x : vert) {
            important[x] = false;
        }
    }
    return 0;
}
