
/// not fixed
vector<char> segmentedSieveNoPreGen(long long L, long long R) {
    vector<char> isPrime(R - L + 1, true);
    long long lim = sqrt(R);
    for (long long i = 2; i <= lim; ++i)
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
            isPrime[j - L] = false;
    if (L == 1)
        isPrime[0] = false;
    return isPrime;
}
vector<ll> seive(ll l,ll r){
    vector<ll> prime;
    auto x=segmentedSieveNoPreGen(1,maxn);
    for(int i=0;i<maxn;i++){
        if(x[i]==true) prime.pb(i);
    }
    return prime;
}

