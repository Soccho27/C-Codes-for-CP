// for finiding maximum in a range

// problem - https://www.hackerrank.com/contests/srbd-code-contest-2024-round-2/challenges/weird-subarray/problem

#include <bits/stdc++.h>
#define int long long
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
const char nl = '\n';
using namespace std;

const int N = 5e5 + 9;
int a[N];
vector<vector<int> > sprs;

struct ST {
  #define lc (n << 1)
  #define rc ((n << 1) | 1)
  long long t[4 * N], lazy[4 * N];
  ST() {
    memset(t, 1, sizeof t);
    memset(lazy, 0, sizeof lazy);
  }
  inline void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    t[n] = max(t[n], lazy[n]);
    if (b != e) {
      lazy[lc] = max(lazy[lc], lazy[n]);
      lazy[rc] = max(lazy[rc], lazy[n]);
    }
    lazy[n] = 0;
  }
  inline long long combine(long long a,long long b) {
    return max(a, b);
  }
  inline void pull(int n) {
    t[n] = max(t[lc], t[rc]);
  }
  void build(int n, int b, int e) {
    lazy[n] = 0;
    if (b == e) {
      if(a[b] > 1)t[n] = 1;
      else t[n] = 0;
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }
  void upd(int n, int b, int e, int i, int j, long long v) {
    push(n, b, e);
    if (j < b || e < i) return;
    if (i <= b && e <= j) {
      lazy[n] = v; //set lazy
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    upd(lc, b, mid, i, j, v);
    upd(rc, mid + 1, e, i, j, v);
    pull(n);
  }
  long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (i > e || b > j) return 0; //return null
    if (i <= b && e <= j) return t[n];
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
}lz;

int gcd(int a, int b){
    if(a == 0)return b;
    else return gcd(b % a, a);
}

int query(int l, int r){
    int k = 31 - __builtin_clz(r - l + 1);
    return gcd(sprs[l][k], sprs[r - (1 << k) + 1][k]);
}

void solve()
{
    int n;cin>>n;
    for(int i = 1; i <= n; i++)cin>>a[i];
    sprs = vector<vector<int> > (n + 1, vector<int> (22, 0));
    for(int i = 1; i <= n; i++){
        sprs[i][0] = a[i];   // a 1 - based
    }
    for(int j = 1; j <= 21; j++){
        for(int i = 1; i <= n; i++){
            sprs[i][j] = gcd(sprs[i][j - 1], sprs[min(n, i + (1 << (j - 1)))][j - 1]);
        }
    }
    lz.build(1, 1, n);
    for(int i = 1; i <= n; i++){
        int lo = 0, hi = n - i, mid, canGo = 0;
        while(lo <= hi){
            mid = (lo + hi) / 2;
            int nw = query(i, i + mid);
            if(nw > 1){
                canGo = mid;
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        if(a[i] != 1)lz.upd(1, 1, n, i, i + canGo, canGo + 1);
    }
    for(int i = 1; i <= n; i++){
        int nw = lz.query(1, 1, n, i, i);
        cout<<nw<<" ";
    }
    cout<<nl;
}

signed main()
{
    fast int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        // cout<<"Case "<<tc<<": ";
        solve();
    }
    return 0;
}