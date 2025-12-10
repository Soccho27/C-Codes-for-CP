5. SegmentTree
vector<int> seg(4*sz+10);
vector<int> a;

int buildSeg(int indx, int lo, int hi){
    if(lo == hi)return seg[indx] = arr[lo];
    int mid = (lo+hi) / 2;
    return seg[indx] = buildSeg(2*indx+1, lo, mid) + buildSeg(2*indx+2, mid+1, hi);
}

int updateSeg(int indx,int lo,int hi,int l,int val){
    if((lo > l) || (hi < l))return seg[indx];
    if(lo == hi && lo == l){
        return seg[indx] = val;
    }
    int mid = (lo + hi) / 2;
    return seg[indx] = updateSeg(2*indx+1, lo, mid, l, val) + updateSeg(2*indx+2, mid+1, hi, l, val);
}

int query(int indx,int lo,int hi,int l,int r){
    if((lo > r) || (hi < l))return 0;//no overlap
    if((lo >= l) && (hi <= r)){return seg[indx];}//exact
    int mid = (lo + hi) / 2;
    return query(2*indx+1, lo, mid, l, r) + query(2*indx+2, mid+1, hi, l, r); // overlap
}


// MAX
int buildSeg(int idx, int lo, int hi) {
    if (lo == hi) return seg[idx] = arr[lo];
    int mid = (lo + hi) / 2;
    return seg[idx] = max(
        buildSeg(idx*2+1, lo, mid),
        buildSeg(idx*2+2, mid+1, hi)
    );
}

int updateSeg(int idx, int lo, int hi, int pos, int val) {
    if (pos < lo || pos > hi) return seg[idx];
    if (lo == hi) return seg[idx] = val;
    int mid = (lo + hi) / 2;
    return seg[idx] = max(
        updateSeg(idx*2+1, lo, mid, pos, val),
        updateSeg(idx*2+2, mid+1, hi, pos, val)
    );
}

int getSeg(int idx, int lo, int hi, int l, int r) {
    if (hi < l || lo > r) return INT_MIN;
    if (l <= lo && hi <= r) return seg[idx];
    int mid = (lo + hi) / 2;
    return max(
        getSeg(idx*2+1, lo, mid, l, r),
        getSeg(idx*2+2, mid+1, hi, l, r)
    );
}

//MIN
int buildSeg(int idx, int lo, int hi) {
    if (lo == hi) return seg[idx] = arr[lo];
    int mid = (lo + hi) / 2;
    return seg[idx] = min(
        buildSeg(idx*2+1, lo, mid),
        buildSeg(idx*2+2, mid+1, hi)
    );
}

int updateSeg(int idx, int lo, int hi, int pos, int val) {
    if (pos < lo || pos > hi) return seg[idx];
    if (lo == hi) return seg[idx] = val;
    int mid = (lo + hi) / 2;
    return seg[idx] = min(
        updateSeg(idx*2+1, lo, mid, pos, val),
        updateSeg(idx*2+2, mid+1, hi, pos, val)
    );
}

int getSeg(int idx, int lo, int hi, int l, int r) {
    if (hi < l || lo > r) return INT_MAX;
    if (l <= lo && hi <= r) return seg[idx];
    int mid = (lo + hi) / 2;
    return min(
        getSeg(idx*2+1, lo, mid, l, r),
        getSeg(idx*2+2, mid+1, hi, l, r)
    );
}
