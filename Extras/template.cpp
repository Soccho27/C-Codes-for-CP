#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

#define int long long
#define fr(i, a, b) for (int i = a; i < b; i++)
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
using namespace __gnu_pbds;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// order_of_key(k) //this returns the count of values that is **less** than k
// find_by_order(k) // this returns the value at index k(0 - based indexing)

const int mod = 1e9 + 7;
const int sz = 2e5 + 5;
const int inf = 1e18;

void solve()
{
    
}

int32_t main()
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