// this problem is for https://codeforces.com/contest/1951/problem/E
#include <bits/stdc++.h>
#define ll long long
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define mmst(i,a) memset(i,a,sizeof(i))
#define all(i) i.begin(),i.end()
#define allr(i) i.rbegin(),i.rend()
#define caseout cout << "Case " << tc << ": ";
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define SS " "
#define dbgd cout<<"D"<<endl;
#define dbg(i) cout<<i<<endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
using namespace std;

const ll mod=1e9+7;
const ll sz=1e6 + 5;
const ll INF=1e18;

ll power(long long n, long long k, const ll mod) {
  ll ans = 1 % mod;
  n %= mod;
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

const ll MOD1 = 127657753, MOD2 = 987654319;
const ll p1 = 137, p2 = 277;
ll ip1, ip2;
pair<ll, ll> pw[sz], ipw[sz];
void prec() {
  pw[0] =  {1, 1};
  for (ll i = 1; i < sz; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] =  {1, 1};
  for (ll i = 1; i < sz; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
  }
}
struct Hashing {
  ll n;
  string s; // 0 - indexed
  vector<pair<ll, ll>> hs; // 1 - indexed
  Hashing() {}
  Hashing(string _s) {
    n = _s.size();
    s = _s;
    hs.emplace_back(0, 0);
    for (ll i = 0; i < n; i++) {
      pair<ll, ll> p;
      p.first = (hs[i].first + 1LL * pw[i].first * s[i] % MOD1) % MOD1;
      p.second = (hs[i].second + 1LL * pw[i].second * s[i] % MOD2) % MOD2;
      hs.push_back(p);
    }
  }
  pair<ll, ll> get_hash(ll l, ll r) { // 1 - indexed
    assert(1 <= l && l <= r && r <= n);
    pair<ll, ll> ans;
    ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
    ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
    return ans;
  }
  pair<ll, ll> get_hash() {
    return get_hash(1, n);
  }
};

void solve()
{
    string s;
    cin>>s;
    ll n = s.size();
    Hashing hs(s);
    string rs = s;
    reverse(all(rs));
    Hashing hrs(rs);
    if(hs.get_hash() != hrs.get_hash()){yes;cout<<"1"<<endl;cout<<s<<endl;return;}
    fr(i,0,n - 1){
        pair<ll, ll> hs1 = hs.get_hash(1, i + 1), hrs1 = hrs.get_hash(n - i, n);
        pair<ll, ll>  hs2 = hs.get_hash(i + 2, n), hrs2 = hrs.get_hash(1, n - i - 1);
        if(hs1 != hrs1 && hs2 != hrs2){
            yes;cout<<"2"<<endl;
            cout<<s.substr(0, i + 1)<<" "<<s.substr(i + 1)<<endl;
            return;
        }
    }
    no;
}

int main()
{
    fast ll T = 1;
    cin >> T;
    prec();
    for (ll tc = 1; tc <= T; tc++)
    {
        // cout<<"Case "<<tc<<": ";
        solve();
    }
    return 0;
}