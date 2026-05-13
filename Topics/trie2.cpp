// problem: https://vjudge.net/contest/802100#problem/E

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mmst(i, a) memset(i,a,sizeof(i))
#define all(i) i.begin(),i.end()
#define SS " "
#define ddd cout<<"D"<<nl;
#define yes cout<<"YES"<<nl
#define no cout<<"NO"<<nl
const char nl = '\n';

const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int sz = 1e6 + 5;
const int inf = 1e18;

struct Trie {
    static const int B = 31;
    struct node {
        node* nxt[2];
        int sz;
        node() {
            nxt[0] = nxt[1] = NULL;
            sz = 0;
        }
    }*root;
    Trie() {
        root = new node();
    }
    void insert(int val) {
        node* cur = root;
        cur -> sz++;
        for (int i = B - 1; i >= 0; i--) {
            int b = val >> i & 1;
            if (cur -> nxt[b] == NULL) cur -> nxt[b] = new node();
            cur = cur -> nxt[b];
            cur -> sz++;
        }
    }
    int get_max(int x) { // returns maximum of val ^ x
        node* cur = root;
        int ans = 0;
        for (int i = B - 1; i >= 0; i--) {
        int k = x >> i & 1;
        if (cur -> nxt[!k]) cur = cur -> nxt[!k], ans <<= 1, ans++;
        else cur = cur -> nxt[k], ans <<= 1;
        }
        return ans;
    }
    
    void delNode(node* cur) {
        for (int i = 0; i < 2; i++) if (cur -> nxt[i]) delNode(cur -> nxt[i]);
        delete(cur);
    }
  
    void del(int val){
        node* cur = root;
        node* prvNode = cur;
        cur -> sz--;
        if(cur -> sz == 0){
            delNode(cur);
            return;
        }
        for (int i = B - 1; i >= 0; i--) {
            int b = val >> i & 1;
            int prvGo = b;
            if (cur -> nxt[b] == NULL)return;
            cur = cur -> nxt[b];
            cur -> sz--;
            // cout<<cur->sz<<nl;
            if(cur -> sz <= 0){
                prvNode -> nxt[prvGo] = NULL;
                delNode(cur);
                return;
            }
            prvNode = cur;
        }
    }
} t;

int ans;
void dfs(int node, int par, vector<int> adj[], int a[]){
    t.insert(a[node]);
    int nw = t.get_max(a[node]);
    ans = max(ans, nw);
    for(auto it: adj[node]){
        if(it == par)continue;
        dfs(it, node, adj, a);
    }
    t.del(a[node]);
}

void solve()
{
    int n;cin>>n;
    int a[n + 1];for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    vector<int> adj[n + 1];
    for(int i = 0; i < n - 1; i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = 0;
    dfs(1, -1, adj, a);
    cout<<ans<<nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        // cout<<"Case "<<tc<<": ";
        solve();
    }
    return 0;
}