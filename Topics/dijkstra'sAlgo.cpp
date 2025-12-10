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
const ll INF=1e15;

void solve()
{
    ll n,m;cin>>n>>m;
    vector<pair<ll, ll> > adj[n + 1];
    vector<ll> fDis(n + 1, INF);
    fr(i,0,m){
        ll u,v,w;cin>>u>>v>>w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll> > , greater<pair<ll, ll> > > pq;
    pq.push({0, 1});    // jetar priority te korte chai seta samne hobe
    while(!pq.empty()){
        ll dis = pq.top().first;
        ll node = pq.top().second;
        pq.pop();
        if(fDis[node] < dis)continue;   // chck
        for(auto it: adj[node]){
            if(it.second + dis < fDis[it.first]){
                fDis[it.first] = it.second + dis;
                pq.push({fDis[it.first], it.first});
            }
        }
    }
    for(ll i = 2; i <= n ; i++){
        cout<<fDis[i]<<" ";
    }cout<<endl;
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