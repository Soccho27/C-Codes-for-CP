{
	// Place your snippets for cpp here. Each snippet is defined under a snippet name and has a prefix, body and 
	// description. The prefix is what is used to trigger the snippet and the body will be expanded and inserted. Possible variables are:
	// $1, $2 for tab stops, $0 for the final cursor position, and ${1:label}, ${2:another} for placeholders. Placeholders with the 
	// same ids are connected.
	// Example:
	// "Print to console": {
	// 	"prefix": "log",
	// 	"body": [
	// 		"console.log('$1');",
	// 		"$2"
	// 	],
	// 	"description": "Log output to console"
	// }
	"Template": {
		"prefix": "qw",
		"body": [
			"#include <bits/stdc++.h>",
			"using namespace std;",
			"#define int long long",
			"#define mmst(i, a) memset(i,a,sizeof(i))",
			"#define all(i) i.begin(),i.end()",
			"#define SS \" \"",
			"#define ddd cout<<\"D\"<<nl;",
			"#define yes cout<<\"YES\"<<nl",
			"#define no cout<<\"NO\"<<nl",
			"const char nl = '\\n';",
			"",
			"const int mod1 = 1e9 + 7;",
			"const int mod2 = 998244353;",
			"const int sz = 1e6 + 5;",
			"const int inf = 1e18;",
			"",
			"void solve()",
			"{",
			"    $0",
			"}",
			"",
			"signed main()",
			"{",
			"    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);",
			"    int T = 1;",
			"    cin >> T;",
			"    for (int tc = 1; tc <= T; tc++)",
			"    {",
			"        // cout<<\"Case \"<<tc<<\": \";",
			"        solve();",
			"    }",
			"    return 0;",
			"}"
		],
		"description": ""
	},
	"Header": {
		"prefix": "qwheadGen",
		"body": [
			"#include <iostream>",
			"#include <math.h>",
			"#include <vector>           // for vectors",
			"#include <algorithm>        // for sorting  // reversing    // min,max",
			"#include <cstring>          // for memset",
			"#include <limits.h>         // long_max",
			"#include <functional>       // for using lamda function",
			""
		],
		"description": "Header"
	},
	"OrderSet": {
		"prefix": "qwordrset",
		"body": [
			"#include<ext/pb_ds/assoc_container.hpp>",
			"#include<ext/pb_ds/tree_policy.hpp>",
			"using namespace __gnu_pbds;",
			"",
			"template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;",
			"template <typename T, typename R> using o_map = tree<T, R, less<T>, rb_tree_tag, tree_order_statistics_node_update>;",
			"template<typename T> using o_multiset = tree<pair<T,int>, null_type, less<pair<T,int>>, rb_tree_tag, tree_order_statistics_node_update>;",
			"",
			"// order_of_key(k) //this returns the count of values that is **less** than k",
			"// find_by_order(k) // this returns the value at index k(0 - based indexing)"
		],
		"description": ""
	},
  "gcd": {
		"prefix": "qwgggcd",
		"body": [
			"int gcd(int a, int b){",
			"    if(a == 0)return b;",
			"    else return gcd(b % a, a);",
			"}"
		],
		"description": ""
	},
	"forLoop": {
		"prefix": "qwfrrr",
		"body": [
			"for(int i = 0; i < n; i++)"
		],
		"description": ""
	},
	"toseetestcaseCF": {
		"prefix": "qwstringoutput",
		"body": [
			"if(tc == 1){",
			"    int n;cin>>n;",
			"    string s = to_string(n);",
			"    int a[n];for(int i = 0; i < n; i++){",
			"        cin>>a[i];",
			"        s += \"_\" + to_string(a[i]);",
			"    }",
			"    cout<<s<<nl;",
			"}",
			"else solve();"
		],
		"description": "toseetestcaseCF"
	},
	"binPow": {
		"prefix": "qwbinpow",
		"body": [
			"int binPow(int a, int b){",
			"    int res = 1;",
			"    while(b > 0){",
			"        if(b & 1){",
			"            res = (res * a) % mod;",
			"        }",
			"        a = (a * a) % mod;",
			"        b >>= 1;",
			"    }",
			"    return res;",
			"}"
		],
		"description": ""
	},
	"prec": {
		"prefix": "qwprec",
		"body": [
			"int fact[sz];",
			"",
			"void prec(){",
			"    fact[0] = 1;",
			"    for(int i = 1; i < sz;i++){",
			"        fact[i] = (fact[i - 1] * i) % mod;",
			"    }",
			"}",
			"",
			"vector<int> primes, isPrime(sz + 1, 1);",
			"",
			"void prec(){",
			"	isPrime[0] = 0, isPrime[1] = 0;",
			"	for(int i = 2;i <= sz; i++){",
			"        if(isPrime[i])primes.push_back(i);",
			"        if(sz / i < i)continue;",
			"		for(int j = i * i; j <= sz; j+= i){",
			"			isPrime[j] = 0;",
			"		}",
			"	}",
			"}",
			"",
			"vector<int> divi[sz + 5];",
			"",
			"void prec(){",
			"    for(int i = 1; i <= sz; i++){",
			"        for(int j = i; j <= sz; j+=i){",
			"            divi[j].push_back(i);",
			"        }",
			"    }",
			"}",
			"",
			"",
			"vector<int> primes, spfa(sz + 1);",
			"",
			"void prec(){",
			"	for(int i = 0; i <= sz; i++)spfa[i] = i;",
			"	for(int i = 2;i <= sz; i++){",
			"        if(spfa[i] != i)continue;",
			"        primes.push_back(i);",
			"        if(sz / i < i)continue;",
			"		for(int j = i * i; j <= sz; j+= i){",
			"			if(spfa[j] != j)continue;",
			"            spfa[j] = i;",
			"		}",
			"	}",
			"}"
		],
		"description": ""
	}
}

	// https://snippet-generator.app