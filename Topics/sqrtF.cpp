int sqrtf(int n){
    int lo = 1, hi = n, mid, res = 0;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(mid <= (n / mid)){
            lo = mid + 1;
            res = mid;
        }
        else hi = mid - 1;
    }
    // cout<<n<<" "<<res<<nl;
    return res;
}