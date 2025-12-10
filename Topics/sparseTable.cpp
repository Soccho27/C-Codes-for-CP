vector<vector<int> > sprs(n + 1, vector<int> (22, 0));
for(int i = 1; i <= n; i++){
    sprs[i][0] = a[i];   // a 1 - based
}
for(int j = 1; j <= 21; j++){
    for(int i = 1; i <= n; i++){
        sprs[i][j] = gcd(sprs[i][j - 1], sprs[min(n, i + (1 << (j - 1)))][j - 1]);
        // int cur = sprs[i][j - 1];
        // int nxtInd = min(n, i + (1LL << (j - 1)));
        // int nxt = sprs[nxtInd][j - 1];
        // int nw = gcd(cur, nxt);
        // sprs[i][j] = nw;
    }
}

int query(int l, int r){
    int k = 31 - __builtin_clz(r - l + 1);
    return gcd(sprs[l][k], sprs[r - (1 << k) + 1][k]);
}