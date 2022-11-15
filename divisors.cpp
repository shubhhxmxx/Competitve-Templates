//use sieve to calculate primes upto x or sqrt(X);

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

vector<ll> prime=primes(maxn);
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
