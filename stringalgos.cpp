#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define For(i,a,b) for(int i=b;i>=a;i--)
#define setter(address,value) memset(address,value,sizeof(address))
#define pb push_back
#define mp make_pair
#define eps 1e-9
//const ints
const int maxn=1e6;
const int mod=1e9+7;


typedef vector<int> vi;
typedef set<int> si;


//   POLYNOMIAL HASH

ll dp[maxn];
ll inv[maxn];
ll power(ll a, ll b){
    if(b==0) return 1;
    ll res=power(a,b/2);
    if(b%2) res=(res%mod*res%mod*a%mod)%mod;
    else res=(res%mod*res%mod)%mod;
    return res;
}
void init(string s)
{
    ll p=31;
    ll p_power=1;
    inv[0]=1;
    dp[0]=s[0]-'a'+1;
    for(int i=1;i<s.size();i++){
        p_power=(p_power*p)%mod;
        inv[i]=power(p_power,mod-2);

        dp[i]=(dp[i-1]+(s[i]-'a'+1)*p_power)%mod;
    }
}
ll substringHash(int l,int r){
    ll result=dp[r];
    if(l>0) result-=dp[l-1];
    return (result*inv[l])%mod;
}

vector<int> kmppre(string z){
	int n=z.length();
	vector<int> f(n);
	f[0]=0;
	for(int i=1;i<n;i++){
		int j=f[i-1];
		while(j>0 && z[i]!=z[j]) j=f[j-1];
		if(z[i]==z[j]) ++j;
		f[i]=j;
		//cout<<j<<endl;
	}
	return f;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--)
    {
     string pat,text;
	cin>>pat>>text;
	string z=pat+"#"+text;
	vector<int> pi=kmppre(z);
	for(int i=pat.length();i<z.length();i++){
        cout<<pi[i]<<" ";
        }
        cout<<endl;
    }
}

