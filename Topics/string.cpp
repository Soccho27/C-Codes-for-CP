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
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
using namespace std;
const ll mod=1e9+7;

string deleteLeadingZeros(string a){
    ll f=1;
    string res="";
    fr(i,0,a.size()){
        if(a[i]=='0'&&f)continue;
        else f=0;
        res+=a[i];
    }
    return res;
}



string stringPlus(string a,string b){
    if(a.size()<b.size())swap(a,b);
    while(b.size()!=a.size())b='0'+b;
    reverse(all(a));reverse(all(b));
    ll ptr=0,carry=0;
    string ans="";
    while(ptr<a.size()){
        ll v1=a[ptr]-'0';
        ll v2=b[ptr]-'0';
        ll v=v1+v2+carry;
        ans+=to_string(v%10);
        v/=10;
        carry=v;
        ptr++;
    }
    ans+=to_string(carry);
    reverse(all(ans));
    ans=deleteLeadingZeros(ans);
    // cout<<ans<<endl;
    return ans;
}



string stringMultiply(string a,string b){
    ll carry=0;
    if(a.size()<b.size())swap(a,b);
    // cout<<a<<" "<<b<<endl;
    ll an=a.size(),bn=b.size();
    reverse(all(a));reverse(all(b));
    vector<string> vecOfRes;
    fr(i,0,bn){
        ll v1=b[i]-'0';
        string res="";
        carry=0;
        fr(j,0,i)res+='0';
        fr(j,0,an){
            ll v2=a[j]-'0';
            ll v=v1*v2+carry;
            // cout<<v2<<endl;
            res+=to_string(v%10);
            carry=v/10;
        }
        res+=to_string(carry);
        reverse(all(res));
        deleteLeadingZeros(res);
        // cout<<res<<endl;
        vecOfRes.push_back(res);
    }
    string ans="0";
    fr(i,0,vecOfRes.size()){
        ans=stringPlus(ans,vecOfRes[i]);
    }
    return ans;
}



void solve()
{
    string a,b;
    cin>>a>>b;
    string ansplus=stringPlus(a,b);
    string ansMultiply=stringMultiply(a,b);
    cout<<ansMultiply<<endl; 
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
}