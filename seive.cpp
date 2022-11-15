
vector<ll> primes(ll n){
    //caluclating primesupton
    vector<bool> visited(n,0);
    vector<ll> ans;
    ans.push_back(2);
    for(int i=3;i<=sqrt(n);i+=2){
        if(!visited[i]){
            ans.push_back(i);
            for(int j=i*i;j<=n;j+=i){
                visited[j]=1;
            }
        }
    }
    return ans;
}
