const int N=200005;
int Trie[30*N][2];
int cnt[30*N];
int Node;
void insert(int x){
    int root=0;
    for(int i=30;i>=0;i--){
        int bt=(x>>i)&1;
        if(Trie[root][bt]==-1){
            Trie[root][bt]=++Node;
        }
        root=Trie[root][bt];
        cnt[root]++;
    }
}
void remove(int x){
    int root=0;
    for(int i=30;i>=0;i--){
        int bt=(x>>i)&1;
        root=Trie[root][bt];
        cnt[root]--;
    }
}
int maxxor(int x){
    int ans=0,root=0;
    for(int i=30;i>=0;i--){
            int bt=(x>>i)&1;
            if(Trie[root][!bt] && cnt[Trie[root][!bt]]){
                root=Trie[root][!bt];
                ans=ans|(1<<i);
            }
            else root=Trie[root][bt];
    }
    return ans;
}
