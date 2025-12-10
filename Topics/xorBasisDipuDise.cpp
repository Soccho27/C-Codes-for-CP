#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pii = array<int, 2>;
using tup = array<int, 3>;
template <typename T>
using order_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct XorBasis {
	vector<int> basis;
	int N = 0, tmp = 0;

	void add(int x) {
		N++;
		tmp |= x;
		for (auto &i : basis) x = min(x, x ^ i);
		
		if(!x) return;
		for (auto &i : basis) {
			if((i ^ x) < i) i ^= x;
		}
		basis.push_back(x);
		sort(basis.begin(), basis.end());
	}

	int size() {
		return (int) basis.size();
	}

	void clear() {
		N = 0, tmp = 0;
		basis.clear();
	}

	bool possible(int x) {
		for (auto &i : basis) x = min(x, x ^ i);
		return !x;
	}

	int maxxor(int x = 0) {
		for (auto &i : basis) x = max(x, x ^ i);
		return x;
	}

	int minxor(int x = 0) {
		for (auto &i : basis) x = min(x, x ^ i);
		return x;
	}

	int cntxor(int x) {
		if(!possible(x)) return 0;
		return (1ll << (N - size()));
	}

	int sumOfAint() {
		int ans = tmp * (1ll << (N - 1));
		return ans;
	}

	int kth(int k) {
		int sz = size();
		if(k > (1ll << sz)) return -1;
		k--;
		int ans = 0;
		for (int i = 0; i < sz; i++) if(k >> i & 1) ans ^= basis[i];
		return ans;
	} 
} xb;

void solve(int tc) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
    	int x; cin >> x;
    	xb.add(x);
    }
    cout << xb.maxxor() << '\n';
    //https://c...content-available-to-author-only...s.fi/problemset/task/3191
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1, tc = 0; //cin >> t;
    while(t--) solve(++tc);
}
