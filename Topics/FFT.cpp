//https://cses.fi/problemset/task/2115
#include <bits/stdc++.h>
#define int long long
#define fr(i, a, b) for (int i = a; i < b; i++)
#define mmst(i, a) memset(i,a,sizeof(i))
#define all(i) i.begin(),i.end()
#define allr(i) i.rbegin(),i.rend()
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define SS " "
#define ddd cout<<"D"<<endl;
#define dd(i) cout<<#i<<" "<<i<<endl;
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
const char nl = '\n';
using namespace std;

const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
const int sz = 1e6 + 5;
const int inf = 1e18;

const int N = 3e5 + 9;

const double PI = acos(-1);
struct base {
    double a, b;
    base(double a = 0, double b = 0) : a(a), b(b) {}
    const base operator + (const base &c) const
        { return base(a + c.a, b + c.b); }
    const base operator - (const base &c) const
        { return base(a - c.a, b - c.b); }
    const base operator * (const base &c) const
        { return base(a * c.a - b * c.b, a * c.b + b * c.a); }
};

void fft(vector<base> &p, bool inv = 0) {
    int n = p.size(), i = 0;
    for(int j = 1; j < n - 1; ++j) {
        for(int k = n >> 1; k > (i ^= k); k >>= 1);
        if(j < i) swap(p[i], p[j]);
    }
    for(int l = 1, m; (m = l << 1) <= n; l <<= 1) {
        double ang = 2 * PI / m;
        base wn = base(cos(ang), (inv ? 1. : -1.) * sin(ang)), w;
        for(int i = 0, j, k; i < n; i += m) {
            for(w = base(1, 0), j = i, k = i + l; j < k; ++j, w = w * wn) {
                base t = w * p[j + l];
                p[j + l] = p[j] - t;
                p[j] = p[j] + t;
            }
        }
    }
    if(inv) for(int i = 0; i < n; ++i) p[i].a /= n, p[i].b /= n;
}
vector<long long> multiply(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size(), t = n + m - 1, sz = 1;
    while(sz < t) sz <<= 1;
    vector<base> x(sz), y(sz), z(sz);
    for(int i = 0 ; i < sz; ++i) {
        x[i] = i < (int)a.size() ? base(a[i], 0) : base(0, 0);
        y[i] = i < (int)b.size() ? base(b[i], 0) : base(0, 0);
    }
    fft(x), fft(y);
    for(int i = 0; i < sz; ++i) z[i] = x[i] * y[i];
    fft(z, 1);
    vector<long long> ret(sz);
    for(int i = 0; i < sz; ++i) ret[i] = (long long) round(z[i].a);
    while((int)ret.size() > 1 && ret.back() == 0) ret.pop_back();
    return ret;
}

void solve()
{
    string s;cin>>s;
    int n;n = s.size();

    vector<int> prefSum(n + 1, 0), boro(n + 1, 0), choto(n + 1, 0);    
    // currently every x^i has a zero co-efficient

    for(int i = 1; i <= n; i++)prefSum[i] = prefSum[i - 1] + s[i - 1] - '0';

    for(int i = 0; i <= n; i++)boro[prefSum[i]]++, choto[n - prefSum[i]]++; 
    // incrementing co-efficients, multiplied with n with choto 
    // because j - i can be negative which maybe cannot be compute with fft

    vector<int> mulPoly = multiply(boro, choto);
    int zeroAns = (mulPoly[n] - (n + 1)) / 2; 
    // (n + 1) is the empty substrings, divide by 2 
    // because we are counting i - j and j - i twice which are same in this case 
    // because i - j = j - i = 0

    cout<<zeroAns<<" ";

    while(mulPoly.size() <= 2 * n)mulPoly.push_back(0); 
    // shohag bhai er template a return vector er size vary kore constraints er upure

    for(int i = n + 1; i <= 2 * n; i++)cout<<mulPoly[i]<<" ";   
    // starting from n because we take only positive power co-efficient
    
    cout<<endl;
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