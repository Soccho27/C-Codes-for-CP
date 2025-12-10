#include<bits/stdc++.h>
using namespace std;
 
const int mod=1e9+7;
vector<vector<int>> mul(vector<vector<int>> &a,vector<vector<int>> &b)
{
	int n=a.size(),m=b[0].size();
	vector<vector<int>> c(n,vector<int>(m,0));
	
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<a[0].size();k++)
				c[i][j]=(c[i][j]+(1ll*a[i][k]*b[k][j])%mod)%mod;
		}
	}
	return c;
}
vector<vector<int>> bp(vector<vector<int>> &a,long b)
{
	vector<vector<int>> res(a.size(),vector<int> (a[0].size(),0));
	for(int i=0;i<a.size();i++)
		res[i][i] = 1;		// transpose matrix
	while(b)
	{
		if(b & 1){
			res=mul(res,a);
		}
		a=mul(a,a);
		b >>= 1;
	}
	return res;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	
	int n;
 
	cin>>n;
	int m,k;
	cin>>m>>k;
	vector<vector<int>> A(n,vector<int> (n,0));
 
	
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		u--;
		v--;
 
		A[u][v]+=1;
	}
 
	A=bp(A,k);
	
	cout<<A[0][n-1];
 
	return 0;
}
