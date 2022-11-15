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



typedef vector<int> vi;
typedef set<int> si;

//const ints
const int maxn=1e6;
const int mod=1e9+7;

//Variables




//                                     METHODS
//                                      MINIMUM SPANNNING TREE

//                                   KRUSKAL's ALGO
struct edge{
    int a,b,w;
};
edge arr[maxn];
int par[maxn];
bool comp(edge a,edge b){
        if(a.w<b.w) return true;
        return false;
}
int findpar(int a){
    if(par[a]==-1) return a;
    return par[a]=findpar(par[a]);
}
void Merge(int a,int b){
    par[a]=b;
}
int main(){
    int n,m;cin>>n>>m;
     FOR(i,0,n+1) par[i]=-1;
    FOR(i,0,m) cin>>arr[i].a>>arr[i].b>>arr[i].w;
    sort(arr,arr+m,comp);
    int sum=0;
    FOR(i,0,m){
        int a=findpar(arr[i].a);
        int b=findpar(arr[i].b);
        cout<<i<<":"<<a<<":"<<b<<":"<<arr[i].w<<endl;
        if(a!=b){
            sum+=arr[i].w;
            Merge(a,b);
        }
    }
    cout<<sum<<endl;
}
