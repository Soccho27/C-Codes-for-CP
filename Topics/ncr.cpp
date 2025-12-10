/*
    edge cases:

    cout<<ncr(0,0)<<" "<<ncr(0,1)<<" "<<ncr(1,0)<<nl;

    etar uttor ashe:
        ncr(0,0) = 1;
        ncr(0,k) = 0;
        ncr(k,0) = 1;
*/


int fact[sz];
int factInv[sz];

int binPow(int a, int b, int mod){
    int res = 1;
    while(b > 0){
        if(b & 1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void prec(){
    fact[0] = 1;
    factInv[0] = 1;
    for(int i = 1; i < sz;i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
    for(int i = 1; i < sz;i++){
        factInv[i] = binPow(fact[i], mod - 2, mod);
    }
}


int ncr(int n, int r){
    if(r > n)return 0;
    int dw = (factInv[r] * factInv[n - r]) % mod;
    return (fact[n] * dw) % mod;
}



....




int fact[sz];

void prec(){
    fact[0] = 1;
    for(int i = 1; i < sz;i++){
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

int binPow(int a, int b, int mod){
    int res = 1;
    while(b > 0){
        if(b & 1){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int ncr(int n, int r){
    int dw = (fact[r] * fact[n - r]) % mod;
    int inv = binPow(dw, mod - 2, mod);
    return (fact[n] * inv) % mod;
}