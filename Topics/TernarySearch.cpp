// this is a solution of https://codeforces.com/contest/1999/problem/G2
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
#define ddd cout<<"D"<<endl;
#define dd(i) cout<<i<<endl;
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const char nl = '\n';
using namespace std;

const ll mod=1e9+7;
const ll sz=2e5 + 5;
const ll inf=1e18;

void solve()
{
    ll lo = 2, hi = 999, ans = 2, mid, mid1, mid2;
    while(lo <= hi){
        mid1 = ((hi - lo) / 3) + lo;    // -- > ((2 * lo + hi) / 3)
        mid2 = hi - ((hi - lo) / 3);    // -- > ((lo + 2 * hi) / 3)
    }
}

int main()
{
    fast ll T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        // cout<<"Case "<<tc<<": ";
        solve();
    }
    return 0;
}