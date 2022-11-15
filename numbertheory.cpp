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

vector<ll> seive(){
    vector<bool> visited(maxn,0);
    vector<ll> ans;
    ans.push_back(2);
    for(int i=3;i<=sqrt(maxn);i+=2){
        if(!visited[i]){
            ans.push_back(i);
            for(int j=i*i;j<=maxn;j+=i){
                visited[j]=1;
            }
        }
    }
    return ans;
}
vector<ll> prime;
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t=1;
    cin>>t;
    prime=seive();
    while(t--){
        ll a,b;
        cin>>a>>b;
        cout<<gcd(a,b)<<endl;
    }
}

