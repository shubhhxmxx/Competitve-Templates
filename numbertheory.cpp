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

//
typedef vector<int> vi;
typedef set<int> si;
//                                          GCD
ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

vector<ll> prime;

// calculates prime of range l,r
// where  r-l can be upto 1e9;

vector<ll> primes(ll n){
    //caluclating primesupton
    vector<bool> visited(n,0);
    vector<ll> ans;
    for(int i=2;i<=sqrt(n);i++){
        if(!visited[i]){
            for(int j=i*i;j<=n;j+=i){
                visited[j]=1;
            }
        }
    }
    FOR(i,1,n+1){
    if(!visited[i]) ans.pb(i);
    }
    return ans;
}

vector<ll> factor(ll x){
    vector<ll> ans;
    ll y=x;
    for(auto fac:prime){
        if(fac==y){
            ans.pb(1);
            ans.pb(fac);
            break;
        }
        if(fac>x) break;
        while(x%fac==0){
            ans.push_back(fac);
            x/=fac;
        }

    }
    return ans;
}
ll binpow(ll a,ll b){
    if(b==0) return 1;
    ll res=binpow(a,b/2);
    if(b%2) return (res%mod*res%mod*a%mod)%mod;
    return (res%mod*res%mod)%mod;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<binpow(a,b)<<endl;
    }
 }

