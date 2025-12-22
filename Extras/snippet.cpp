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
			"#define pp(x) cout<<x<<nl",
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
	}
}

	// https://snippet-generator.app