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

const int mod = 1e9 + 7;
const int sz = 1e6 + 5;
const int inf = 1e18;
int a[sz][sz];
int x, y;

void upd(int k, int l, int op){
    while(op--){
        a[x][y] = op;
        x+=k,y+=l;
    }
}

void solve()
{
    int n;cin>>n;
    x = n / 2, y = n / 2;
    int nw = 0, cur = 0;
    a[x][y] = 0, nw++, y++;
    a[x][y] = 1, nw++, x++;
    while(nw < n * n){
        
    }
}

signed main()
{
    fast int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        // cout<<"Case "<<tc<<": ";
        solve();
    }
    return 0;
}