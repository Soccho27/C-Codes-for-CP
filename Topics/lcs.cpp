/* Dynamic Programming implementation of LCS problem */
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
void lcs(char* X, char* Y, int m, int n)
{
	int L[m + 1][n + 1];

	/* Following steps build L[m+1][n+1] in bottom up
	fashion. Note that L[i][j] contains length of LCS of
	X[0..i-1] and Y[0..j-1] */
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// Following code is used to print LCS
	int index = L[m][n];

	// Create a character array to store the lcs string
	char lcs[index + 1];
	lcs[index] = '\0'; // Set the terminating character

	// Start from the right-most-bottom-most corner and
	// one by one store characters in lcs[]
	int i = m, j = n;
	while (i > 0 && j > 0) {
		// If current character in X[] and Y are same, then
		// current character is part of LCS
		if (X[i - 1] == Y[j - 1]) {
			lcs[index - 1]
				= X[i - 1]; // Put current character in result
			i--;
			j--;
			index--; // reduce values of i, j and index
		}

		// If not same, then find the larger of two and
		// go in the direction of larger value
		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}

	// Print the lcs
	cout << "LCS of " << X << " and " << Y << " is " << lcs;
}

/* Driver program to test above function */
int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	int m = strlen(X);
	int n = strlen(Y);
	lcs(X, Y, m, n);
	return 0;
}

// mycode

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
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
using namespace std;

const ll mod=1e9+7;
const ll sz=1e6;
const ll INF=1e9;

void solve(string x,string y,ll n,ll m)
{
    ll lcs[n+1][m+1];
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=m;j++){
            if(i == 0 || j == 0){
                lcs[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){                        // x[i-1] er sthe compare not x[i]
                lcs[i][j]=1+lcs[i-1][j-1];
            }
            else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
    }
    ll indx=lcs[n][m];
    string lcsString="";
    // indx--;
    ll i=n+1,j=m+1;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){                     // x[i-1] er sthe compare not x[i]
            lcsString=x[i-1]+lcsString;
            i--,j--;
        }
        else if(lcs[i-1][j]>lcs[i][j-1])i--;
        else j--;
    }
    cout<<indx<<endl;
    cout<<lcsString<<endl;
}
int main()
{
    fast ll T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        string X = "AGGTAB";
        string Y = "GXTXAYB";
        int n = X.size();
        int m = Y.size();
        solve(X, Y, n, m);
    }
}
