const int mod=1e9+7;
ll binpow(ll a,ll b){
    if(b==0) return 1;
    ll res=binpow(a,b/2);
    if(b%2) return (res%mod*res%mod*a%mod)%mod;
    return (res%mod*res%mod)%mod;
}
