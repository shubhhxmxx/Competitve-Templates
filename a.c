#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define For(i,a,b) for(ll  i=b;i>=a;i--)
#define setter(address,value) memset(address,value,sizeof(address))
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define pii pair<ll ,ll >
#define nl cout<<endl
#define what_is(x) cerr << #x << " is " << x << endl;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define rint1(x) ll  x; cin>>x;
#define rint2(x,y) ll  x,y; cin>>x>>y;
#define all(v) v.begin(),v.end()


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

template<typename T,typename... Args>
T sum(T a,Args... args) {return a+sum(args...);}



//const ints
const int maxn=1e6;
const int mod=1e9+7;

//
typedef vector<int> vi;
typedef set<int> si;


//             METHODS
ll ceil(ll a,ll b){
    if(a%b) return a/b+1;
    else return a/b;
}




void solve(){
    rint1(n);
    int a[n+1];
    rep(i,0,n) cin>>a[i];
    sort(a,a+n);
    int ans=0;
    rep(i,0,n-1){
        ans=max({ans,a[i],a[i+1]-a[i]});
    }
    cout<<ans<<endl;
}



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}
