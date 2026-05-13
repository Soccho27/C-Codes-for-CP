// problem: https://vjudge.net/contest/802100#problem/E


//#pragma GCC optimize("unroll-loops,-O3,Ofast,fast-math,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <typename T> using o_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template <typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;
// #define int long long
#define double long double
#define pii pair<int, int>
#define tii array <int, 3>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define eps 1e-9
#define inf 1e9
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define accu(x) accumulate(all(x), (int)0)

const int N = 5e5 + 9;
vector <int> adj[N];
int a[N];

int ans;
int tr[N * 30][2], cnt[60 * N];
int node = 0;

void insert(int num)
{
    int curr = 0;
    for (int i = 29; i >= 0; i--)
    {
        int bit = num >> i & 1;
        if (tr[curr][bit] == 0) tr[curr][bit] = ++node;
        curr = tr[curr][bit];
        cnt[curr]++;
    }
}

void remove(int num)
{
    int curr = 0;
    for (int i = 29; i >= 0; i--)
    {
        int bit = num >> i & 1;
        curr = tr[curr][bit];
        cnt[curr]--;
    }
}

int find_max(int num)
{
    int ans = 0, curr = 0;
    for (int i = 29; i >= 0; i--)
    {
        ans *= 2;
        int bit = num >> i & 1;
        if (tr[curr][!bit] && cnt[tr[curr][!bit]])
        {
            ans++;
            curr = tr[curr][!bit];
        }
        else if (tr[curr][bit] && cnt[tr[curr][bit]])
        {
            curr = tr[curr][bit];
        }
        else return 0;
    }
    return ans;
}

void dfs (int node, int par)
{
    ans = max(ans, find_max(a[node]));

    insert(a[node]);
    for (auto &it : adj[node])
    {
        if (it == par) continue;
        dfs(it, node);
    }
    remove(a[node]);
}

signed main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    cout << ans << "\n";

    return 0;
}