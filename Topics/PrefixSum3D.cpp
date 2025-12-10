#include <bits/stdc++.h>
#define ll long long
#define fr(i, a, b) for (ll i = a; i < b; i++)
#define mmst(i,a) memset(i,a,sizeof(i))
#define all(i) i.begin(),i.end()
#define allr(i) i.rbegin(),i.rend()
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
#define SS " "
#define ddd cout<<"D"<<endl;
#define dd(i) cout<<i<<endl;
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
const char nl = '\n';
using namespace std;

const ll mod = 998244353;
const ll sz = 5000;
const ll inf = 1e18;

void solve()
{
	ll n;cin>>n;
	ll a[n + 1][n + 1][n + 1], pre[n + 1][n + 1][n + 1];
	for(ll i = 0; i <= n; i++){
		for(ll j = 0; j <= n; j++){
			for(ll k = 0; k <= n; k++){
				if(i == 0 || j == 0 || k == 0){pre[i][j][k] = 0;continue;}
				cin>>a[i][j][k];
				pre[i][j][k] = pre[i - 1][j][k] + pre[i][j - 1][k] + pre[i][j][k - 1] 
								- pre[i - 1][j - 1][k] - pre[i - 1][j][k - 1] - pre[i][j - 1][k - 1]
									+ pre[i - 1][j - 1][k - 1] + a[i][j][k];
			}
		}
	}
	ll q;cin>>q;
	while(q--){
		ll l1,r1,l2,r2,l3,r3;cin>>l1>>r1>>l2>>r2>>l3>>r3;
		ll ans = pre[r1][r2][r3] - pre[l1 - 1][r2][r3] - pre[r1][l2 - 1][r3] - pre[r1][r2][l3 - 1]
					+ pre[l1 - 1][l2 - 1][r3] + pre[l1 - 1][r2][l3 - 1] + pre[r1][l2 - 1][l3 - 1]
						- pre[l1 - 1][l2 - 1][l3 - 1];
		cout<<ans<<nl;
	}
}

int main()
{
	fast ll T = 1;
	// cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		// cout<<"Case "<<tc<<": ";
		solve();
	}
	return 0;
}