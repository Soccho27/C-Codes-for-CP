// /* Dynamic Programming solution to construct Longest
// Increasing Subsequence */
// #include <iostream>
// #include <vector>
// using namespace std;

// // Utility function to print LIS
// void printLIS(vector<int>& arr)
// {
// 	for (int x : arr)
// 		cout << x << " ";
// 	cout << endl;
// }

// // Function to construct and print Longest Increasing
// // Subsequence
// void constructPrintLIS(int arr[], int n)
// {
// 	// L[i] - The longest increasing sub-sequence 
// 	// ends with arr[i]
// 	vector<vector<int> > L(n);

// 	// L[0] is equal to arr[0]
// 	L[0].push_back(arr[0]);

// 	// start from index 1
// 	for (int i = 1; i < n; i++)
// 	{
// 		// do for every j less than i
// 		for (int j = 0; j < i; j++)
// 		{
// 			/* L[i] = {Max(L[j])} + arr[i]
// 			where j < i and arr[j] < arr[i] */
// 			if ((arr[i] > arr[j]) &&
// 					(L[i].size() < L[j].size() + 1))
// 				L[i] = L[j];
// 		}

// 		// L[i] ends with arr[i]
// 		L[i].push_back(arr[i]);
// 	}

// 	// L[i] now stores increasing sub-sequence of
// 	// arr[0..i] that ends with arr[i]
// 	vector<int> max = L[0];

// 	// LIS will be max of all increasing sub-
// 	// sequences of arr
// 	for (vector<int> x : L)
// 		if (x.size() > max.size())
// 			max = x;

// 	// max will contain LIS
// 	printLIS(max);
// }

// // Driver function
// int main()
// {
// 	int arr[] = { 3, 2, 6, 4, 5, 1 };
// 	int n = sizeof(arr) / sizeof(arr[0]);

// 	// construct and print LIS of arr
// 	constructPrintLIS(arr, n);

// 	return 0;
// }
/*
// lis with lcs

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

//function to return size of array without duplicates
int removeDuplicates(vector<int> &arr)
{
	int k = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] != arr[k]) {
			arr[++k] = arr[i];
		}
	}
	return k + 1;
}
// Function to return the size of the
// longest increasing subsequence
int LISusingLCS(vector<int>& seq)
{
	int n = seq.size();

	// Create an 2D array of integer
	// for tabulation
	vector<vector<int> > L(n + 1, vector<int>(n + 1));

	// Take the second sequence as the sorted
	// sequence of the given sequence
	vector<int> sortedseq(seq);

	sort(sortedseq.begin(), sortedseq.end());
	//remove duplicates
	int m = removeDuplicates(sortedseq);
	// Classical Dynamic Programming algorithm
	// for Longest Common Subsequence
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (seq[i - 1] == sortedseq[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	// Return the ans
	return L[n][m];
}

// Driver code
int main()
{

	vector<int> sequence(6);
    sequence[0]=12;
    sequence[1]=34;
    sequence[2]=1;
    sequence[3]=5;
    sequence[4]=40;
    sequence[5]=80;

	cout << LISusingLCS(sequence) << endl;

	return 0;
}
*/
// my code

#include <bits/stdc++.h>
#define ll int
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

void solve(vector<ll>& arr,ll n)
{
    vector<ll> arr2=arr;
    sort(all(arr2));
    ll m=0;
    // collecting unique elements
    for(ll i=1;i < n;i++){
        if(arr2[m]!=arr2[i]){arr2[++m]=arr2[i];}
    }
    for(ll i=0;i <= m;i++){
        cout<<arr2[i]<<" ";
    }cout<<endl;
    m++;
    cout<<m<<endl;
    // vector<ll> lis(n+1,)
    ll lis[n+1][m+1];
    for(ll i=0;i <= n;i++){
        for(ll j=0;j<=m;j++){
            if(i==0||j==0)lis[i][j]=0;
            else if(arr[i-1]==arr2[j-1]){
                lis[i][j]=1+lis[i-1][j-1];
            }
            else if(lis[i-1][j]>lis[i][j-1])lis[i][j]=lis[i-1][j];
            else lis[i][j]=lis[i][j-1];
        }
    }
    string ans="";
    ll i=n,j=m;
    while(i>0&&j>0){
        if(arr[i-1]==arr2[j-1]){ans=to_string(arr[i-1])+" "+ans;i--,j--;}
        else if(lis[i-1][j]>lis[i][j-1])i--;
        else j--;
    }
    cout<<lis[n][m]<<endl;
    cout<<ans<<endl;
}
int main()
{
    fast ll T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        vector<int> sequence(6);
        sequence[0]=12;
        sequence[1]=34;
        sequence[2]=1;
        sequence[3]=5;
        sequence[4]=40;
        sequence[5]=80;
        solve(sequence,6);
    }
}