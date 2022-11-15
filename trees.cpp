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


//                                                      LEAST COMMON ANCESTOR
int level[maxn],parent[maxn];
vector<int> a[maxn];
bool visited[maxn];
void dfs(int src,int par){
    visited[src]=1;
    parent[src]=par;
    level[src]=level[par]+1;
    for(auto x: a[src]){
        if(!visited[x]) dfs(x,src);
    }
}
//                                                      NAIVE
int lca(int a,int b){
    if(level[a]>level[b]) swap(a,b);
    int d=level[b]-level[a];
    cout<<a<<":"<<b<<endl;
    while(d){
        b=parent[b];
        d--;
    }
    if(a==b) return a;
    while(a!=b){
        a=parent[a];
        b=parent[b];
    }
    return a;
}

//                                                       BINARY LIFTING
const int maxN=1e3;
int spars[maxN][maxN];
int n;
void dfs1(int src,int par){
    spars[src][0]=par;
    level[src]=level[par]+1;
    //cout<<src<<":"<<par<<endl;
    for(auto x: a[src]){
        if(x!=par) dfs1(x,src);
    }
}
void init(int src){
    level[src]=0;
    dfs1(src,0);
    //FOR(i,0,n) cout<<spars[i][0]<<" ";
   // cout<<endl;
    for(int j=1;j<=maxN;j++){
        for(int i=1;i<=n;i++){
            if(spars[i][j-1]!=-1){
                int par=spars[i][j-1];
                spars[i][j]=spars[par][j-1];
            }
        }
    }
}
int LCA(int a,int b){
    FOR(i,0,n) FOR(j,0,sqrt(maxn)) spars[i][j]=-1;
    init(1);
    cout<<level[a]<<"::"<<level[b]<<endl;
    if(level[a]>level[b]) swap(a,b);
    int d=level[b]-level[a];
    while(d>0){
        int i=log2(d);
        b=spars[b][i];
        d-=1<<i ;
    }
    if(a==b) return a;
    //while(spars[a][0]!=spars[b][0]){
      //  a=spars[a][0];
       // b=spars[b][0];
    //}
    for(int i=maxN;i>=0;i--){
        if(spars[a][i]!=-1 && (spars[a][i]!=spars[b][i])){
            a=spars[a][i];
            b=spars[b][i];
            cout<<a<<":"<<b<<endl;
        }
    }
    return spars[a][0];
}


//                       DISTANCE BETWEEN TWO NODES IN LOG N
 int getdist(int a,int b){
    int x=LCA(a,b);
    //cout<<x<<endl;
    //cout<<level[x];
    return level[a]+level[b]-2*level[x];
 }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t=1;
   // cin>>t;
    while(t--){
        int m,x,y;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            a[x].pb(y);
        }

    }
}
/*10 9
1 2
1 3
2 7
2 4
3 5
3 6
7 8
8 9
9 10
7 4  */
