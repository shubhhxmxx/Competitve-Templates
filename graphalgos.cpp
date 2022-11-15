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
//                                  TRAJANS ALGO : to find scc using lowtime;
{//
/*stack<int> st;
bool onstack[maxn];
vector<int> a[maxn],tra[maxn];
int timer=1,scc=0;
bool visited[maxn];
int in[maxn],low[maxn];
void dfs(int src){
    //cout<<src<<endl;
    visited[src]=1;
    onstack[src]=1;
    st.push(src);
    in[src]=low[src]=timer++;
    for(auto x:a[src]){
        if(visited[x]==1 && onstack[x]==1){
                low[src]=min(in[x],low[src]);
        }
        else{
            if(visited[x]==false){
                dfs(x);
                if(onstack[x]==true) low[src]=min(low[src],low[x]);
            }
        }
    }
        if(in[src]==low[src]){
            scc++;
            cout<<"scc #"<<scc<<endl;
            while(true && st.size()){
                int u=st.top();
                st.pop();
                onstack[u]=0;
                cout<<u<<" ";
                if(u==src) break;
            }
            cout<<endl;
        }
    }
*/
}

//                                   CYCLE DETETCTION
{

/*

vector<int> a[maxn];
bool visited[maxn];
int par[maxn];

//                                                                       BFS

bool bfs(int node){

    visited[node]=1;
    queue<int> q;
    q.push(node);
    par[node]=-1;
    while(q.size()){
        int child=q.front();
        q.pop();
        for(auto x:a[child]){
            if(!visited[x]){
                visited[x]=1;
                par[x]=child;
                q.push(x);
            }
            else if(par[child]!=x) return true;
        }
    }
    return false;
}
*/
}
//                                          DFS
{

/*
bool dfs(int node,int par){
   // cout<<node<<endl;
    visited[node]=1;
    for(auto x:a[node]){
        if(visited[x]==0){
            if(dfs(x,node)==true) return true;
            }
        else if(x!=par) return true;

    }
    return false;
}
*/

}
//                                         COUNTING CONNECTED COMPONENTS
{

/*vector<int> a[maxn];
bool visited[maxn];
int cnt=0;
void dfs(int src){
    visited[src]=1;
    for(auto x:a[src]){
        if(!visited[x]) dfs(x);
    }
}
int counter(int n){
    setter(visited,0);
    for(int i=1;i<=n;i++){
        if(!visited[i]) {dfs(i); cnt++;}
    }
    return cnt;
}*/

}
//                                          BIPARTITE TEST
{

vector<int> a[maxn];
int color[maxn];
bool visited[maxn];
bool dfs(int src,int c){
    color[src]=c;
    visited[src]=1;
    for(auto x:a[src]){
        if(!visited[x]) if(dfs(x,c^1)) return true;
        if(visited[x] && color[x]==color[src]) return false;
    }
    return true;
}
}


//                                      LEAST COMMON ANCESTOR
//                                          NAIVE
{

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
}

//                                          BINARY LIFTING
{

const int maxN=1e3;
int spars[maxN][maxN];
int n;
void dfs1(int src,int par){
    spars[src][0]=par;
    //cout<<src<<":"<<par<<endl;
    for(auto x: a[src]){
        if(x!=par) dfs1(x,src);
    }
}

void init(int src){
    dfs1(src,-1);
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
    if(level[a]>level[b]) swap(a,b);
    int d=level[b]-level[a];
    while(d>0){
        int i=log2(d);
        b=spars[b][i];
        d-=1<<i ;
    }
    if(a==b) return a;
    while(spars[a][0]!=spars[b][0] && a!=-1 && b!=-1){
        cout<<a<<":"<<b<<endl;
        a=spars[a][0];
        b=spars[b][0];
    }
    return spars[a][0];
}

}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>x>>y;
            a[x].pb(y);
            a[y].pb(x);
        }
        cin>>x>>y;
        cout<<lca(x,y)<<endl;



    }
}
