#include<bits/stdc++.h>
using namespace std;
#define INF 100000000
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
//

//                                       SINGLE SOURCE SHORTEST PATH TREES;


/*
vector<int> a[maxn];
int dist[maxn];
bool visited[maxn];
void bfs(int src){
    queue<int> q;
    visited[src]=1;
    dist[src]=0;
    q.push(src);
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto c:a[x]){
            if(!visited[c]){
                dist[c]=dist[x]+1;
                q.push(c);
                visited[c]=1;
            }
        }
    }
}
void singlesourceshortestpath(int src,int n){
    bfs(src);
    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
    cout<<endl;
}
*/
//                                       DIJSKTRA s ALGORITHM

vector<pair<int,int>> a[maxn];
int dist[maxn];
void dijsktra(int src){
    priority_queue<pair<int,int>> pq;
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty()){
        auto x=pq.top();
        int curr=x.second;
        int discurr=x.first;
        pq.pop();
        for(auto edge:a[curr]){
            if(discurr+edge.second<dist[edge.first]){
                dist[edge.first]=discurr+edge.second;
                pq.push({dist[edge.first],edge.first});
            }
        }
    }
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t=1;
    cin>>t;
    while(t--){
        int n,m,x,y,w;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            cin>>x>>y>>w;
            a[x].pb({y,w});
            a[y].pb({x,w});

        }
        int src;
        for(int i=0;i<=n;i++) dist[i]=INF;
        cin>>src;
        dijsktra(src);
        for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
        cout<<endl;

    }
}
