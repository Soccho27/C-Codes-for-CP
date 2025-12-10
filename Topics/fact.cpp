vector<ll> fact(sz + 1);

void prec(){
    fact[0] = 1;
    for(ll i = 1; i <= sz; i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
}