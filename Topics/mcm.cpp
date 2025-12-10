// // C++ program to print optimal parenthesization
// // in matrix chain multiplication.
// #include <bits/stdc++.h>
// using namespace std;

// // Function for printing the optimal
// // parenthesization of a matrix chain product
// void printParenthesis(int i, int j, int n, int* bracket,
// 					char& name)
// {
// 	// If only one matrix left in current segment
// 	if (i == j) {
// 		cout << name++;
// 		return;
// 	}

// 	cout << "(";

// 	// Recursively put brackets around subexpression
// 	// from i to bracket[i][j].
// 	// Note that "*((bracket+i*n)+j)" is similar to
// 	// bracket[i][j]
// 	printParenthesis(i, *((bracket + i * n) + j), n,
// 					bracket, name);

// 	// Recursively put brackets around subexpression
// 	// from bracket[i][j] + 1 to j.
// 	printParenthesis(*((bracket + i * n) + j) + 1, j, n,
// 					bracket, name);
// 	cout << ")";
// }

// // Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
// // Please refer below article for details of this
// // function
// // https://goo.gl/k6EYKj
// void matrixChainOrder(int p[], int n)
// {
// 	/* For simplicity of the program, one extra
// 	row and one extra column are allocated in
// 		m[][]. 0th row and 0th column of m[][]
// 		are not used */
// 	int m[n][n];

// 	// bracket[i][j] stores optimal break point in
// 	// subexpression from i to j.
// 	int bracket[n][n];

// 	/* m[i,j] = Minimum number of scalar multiplications
// 	needed to compute the matrix A[i]A[i+1]...A[j] =
// 	A[i..j] where dimension of A[i] is p[i-1] x p[i] */

// 	// cost is zero when multiplying one matrix.
// 	for (int i = 1; i < n; i++)
// 		m[i][i] = 0;

// 	// L is chain length.
// 	for (int L = 2; L < n; L++)
// 	{
// 		for (int i = 1; i < n - L + 1; i++) 
// 		{
// 			int j = i + L - 1;
// 			m[i][j] = INT_MAX;
// 			for (int k = i; k <= j - 1; k++) 
// 			{
// 				// q = cost/scalar multiplications
// 				int q = m[i][k] + m[k + 1][j]
// 						+ p[i - 1] * p[k] * p[j];
// 				if (q < m[i][j]) 
// 				{
// 					m[i][j] = q;

// 					// Each entry bracket[i,j]=k shows
// 					// where to split the product arr
// 					// i,i+1....j for the minimum cost.
// 					bracket[i][j] = k;
// 				}
// 			}
// 		}
// 	}

// 	// The first matrix is printed as 'A', next as 'B',
// 	// and so on
// 	char name = 'A';

// 	cout << "Optimal Parenthesization is : ";
// 	printParenthesis(1, n - 1, n, (int*)bracket, name);
// 	cout << "\nOptimal Cost is : " << m[1][n - 1];
// }

// // Driver code
// int main()
// {
// 	int arr[] = { 40, 20, 30, 10, 30 };
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	matrixChainOrder(arr, n);
// 	return 0;
// }

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
ll bracket[100][100];


void printBracket(ll i,ll j,char& name){
    if(i==j){
        cout<<name;
        name++;
        return;
    }
    cout<<"(";
    printBracket(i,bracket[i][j],name);
    printBracket(bracket[i][j]+1,j,name);
    cout<<")";
}


void solve(ll arr[],ll n)
{
    ll matrix[n][n];

    fr(i,0,n){
        // fr(j,0,n)matrix[i][j]=1e9;
        matrix[i][i]=0;
    }
    for(ll l=2;l<=n;l++){
        for(ll i=0;i<n-l+1;i++){
            ll j=i+l-1;
            matrix[i][j]=INF;
            for(ll k=i;k<=j-1;k++){
                ll q=matrix[i][k]+matrix[k+1][j]+arr[i-1]*arr[k]*arr[j];
                if(matrix[i][j]>q){
                    matrix[i][j]=q;
                    bracket[i][j]=k;
                }
            }
        }
    }
    char name='A';
    printBracket(1,n-1,name);   // eta 1 theke shuru
    cout<<endl;
    cout<<matrix[1][n-1]<<endl;
}
int main()
{
    fast ll T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        // cout<<"Case "<<tc<<": ";
        ll arr[] = { 40, 20, 30, 10, 30 };
        ll n = sizeof(arr) / sizeof(arr[0]);
        solve(arr, n);
    }
}