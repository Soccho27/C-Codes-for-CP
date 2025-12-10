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

.

int binPow(int a, int b){
    int res = 1;
    while(b > 0){
        if(b & 1){
            res = (res * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return res;
}

.

int binPow(int a, int b, int mod){
    int res = 1;
    for(;b;b >>= 1, a = (a * a) % mod)if(b & 1)res = res * a % mod;
    return res;
}