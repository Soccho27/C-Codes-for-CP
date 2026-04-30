5. SegmentTree

// l,r SUM
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
    if((lo > r) || (hi < l))return 0;
    if((lo >= l) && (hi <= r)){return seg[indx];}
    int mid = (lo + hi) / 2;
    return query(2*indx+1, lo, mid, l, r) + query(2*indx+2, mid+1, hi, l, r);
}


//MAX
vector<int> seg(4*sz+10);

int updateSeg(int indx,int lo,int hi,int l,int val){
    if((lo > l) || (hi < l))return seg[indx];
    if(lo == hi && lo == l){
        return seg[indx] = val;
    }
    int mid = (lo + hi) / 2;
    return seg[indx] = max(updateSeg(2*indx+1, lo, mid, l, val), updateSeg(2*indx+2, mid+1, hi, l, val));
}

int query(int indx,int lo,int hi,int l,int r){
    if((lo > r) || (hi < l))return -inf;
    if((lo >= l) && (hi <= r)){return seg[indx];}
    int mid = (lo + hi) / 2;
    return max(query(2*indx+1, lo, mid, l, r), query(2*indx+2, mid+1, hi, l, r));
}


// l,r range maximum value with it's index(witout update function)
vector<pair<int, int> > seg(4*sz+10);
vector<int> v;
 
pair<int, int> buildSeg(int indx, int lo, int hi){
    if(lo == hi)return seg[indx] = {v[lo], lo};
    int mid = (lo+hi) / 2;
    auto it1 = buildSeg(2*indx+1, lo, mid), it2 = buildSeg(2*indx+2, mid+1, hi);
    if(it1.first >= it2.first){
        return seg[indx] = it1;
    }
    else {
        return seg[indx] = it2;
    }
}
 
pair<int, int> query(int indx,int lo,int hi,int l,int r){
    if((lo > r) || (hi < l))return {-inf,0};
    if((lo >= l) && (hi <= r)){return seg[indx];}
    int mid = (lo + hi) / 2;
    auto it1 = query(2*indx+1, lo, mid, l, r), it2 = query(2*indx+2, mid+1, hi, l, r);
    if(it1.first >= it2.first)return it1;
    else return it2;
}