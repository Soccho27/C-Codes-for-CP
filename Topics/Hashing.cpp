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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
using namespace std;

const ll mod=1e9+7;
const ll sz=2e5;
const ll INF=1e18;

int power(long long n, long long k, const int mod) {
  int ans = 1 % mod;
  n %= mod;
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[sz], ipw[sz];
void prec() {
  pw[0] =  {1, 1};
  for (int i = 1; i < sz; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % MOD1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % MOD2;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] =  {1, 1};
  for (int i = 1; i < sz; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % MOD1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % MOD2;
  }

}
struct Hashing {
  int n;
  string s; // 0 - indexed
  vector<pair<int, int>> hs; // 1 - indexed
  Hashing() {}
  Hashing(string _s) {
    n = _s.size();
    s = _s;
    hs.emplace_back(0, 0);
    for (int i = 0; i < n; i++) {
      pair<int, int> p;
      p.first = (hs[i].first + 1LL * pw[i].first * (s[i] - 'a' + 1) % MOD1) % MOD1;
      p.second = (hs[i].second + 1LL * pw[i].second * (s[i] - 'a' + 1) % MOD2) % MOD2;
      hs.push_back(p);
    }
  }
  pair<int, int> get_hash(int l, int r) { // 1 - indexed
    assert(1 <= l && l <= r && r <= n);
    pair<int, int> ans;
    ans.first = (hs[r].first - hs[l - 1].first + MOD1) * 1LL * ipw[l - 1].first % MOD1;
    ans.second = (hs[r].second - hs[l - 1].second + MOD2) * 1LL * ipw[l - 1].second % MOD2;
    return ans;
  }
  pair<int, int> get_hash() {
    return get_hash(1, n);
  }
};

bool check(ll ptr, ll len, ll r, ll  n, Hashing& Hs, Hashing& Hrs){
    while(ptr <= r){
        ll l1 = ptr - len + 1, r1 = ptr, l2 = n - ptr + 1, r2 = n - (ptr - len);
        // cout<<l1<<SS<<r1<<SS<<l2<<SS<<r2<<endl;
        auto h1 = Hs.get_hash(l1, r1);
        auto h2 = Hrs.get_hash(l2, r2);
        // cout<<h1.first<<SS<<h2.first<<endl;
        if(h1 != h2){return true;}
        ptr++;
    }
    return false;
}

void solve()
{
    ll n, m, ans = 0;
    cin>>n>>m;
    string s, rs;
    cin>>s;
    rs = s;
    reverse(all(rs));
    Hashing Hs(s);
    Hashing Hrs(rs);
    // auto h1 = Hashing(s).get_hash();
    // cout<<h1.first<<endl;
    while(m--){
        ans = 0;
        ll l, r;
        cin>>l>>r;
        ll tempn = r - l + 1;
        ll len1 = tempn - 2, len2 = tempn - 1, len3 = tempn;
        ll ptr = r - 2, ans1 = 0, ans2 = 0, ans3 = 0;
        if(len1 > 0 && check(ptr, len1, r, n, Hs, Hrs))ans1++;
        ptr = r - 1;
        if(len2 > 0 && check(ptr, len2, r, n, Hs, Hrs))ans2++;
        ptr = r;
        if(len3 > 0 && check(ptr, len3, r, n, Hs, Hrs))ans3++;
        // cout<<len1<<SS<<len2<<SS<<len3<<endl;
        if(ans1)ans += (len1%2)? ((len1 + 1)/2)*((len1 + 1)/2) - 1: (len1/2)*((len1/2) + 1);
        if(ans2)ans += (len2%2)? ((len2 + 1)/2)*((len2 + 1)/2) - 1: (len2/2)*((len2/2) + 1);
        if(ans3)ans += len3;
        cout<<ans<<endl;
    }
}


int main()
{
    fast ll T = 1;
    cin >> T;
    prec();
    for (int tc = 1; tc <= T; tc++)
    {
        // cout<<"Case "<<tc<<": ";

        solve();
    }
    return 0;
}