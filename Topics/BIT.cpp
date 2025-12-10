/*
    https://www.youtube.com/watch?v=CWDQJGaN1gY
*/


vector<int> a, bit;
int n;

void update(int i, int val){
    for(; i <= n; i += (i & -i))bit[i] += val;
}

int query(int i){
    int res = 0;
    for(; i > 0 ; i -= (i & -i))res += bit[i];
    return res;
}

int getSum(int l, int r){
    return query(r) - query(l - 1);
}