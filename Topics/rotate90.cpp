
void rotate90(vector<vector<char> >& mat, int n){
    vector<vector<char> > res(n + 1, vector<char> (n + 1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // res[i][j] = mat[j][n - i - 1]; // anti - clockwise
            res[j][n - i - 1] = mat[i][j];  // clock - wise
        }
    }
    mat = res;
    return;
}


vector<vector<char> > res(sz + 1, vector<char> (sz + 1));
void rotate90custom(vector<vector<char> >& mat, int n, int nw){
    // rotating only nw no. square
    
    int lst = n - nw - 1;
    for(int j = nw; j < n - nw; j++){
        // res[nw][j] = mat[j][n - nw - 1]; // anti
        res[j][n - nw - 1] = mat[nw][j];
    }
    for(int i = nw; i < n - nw; i++){
        // res[i][lst] = mat[lst][n - i - 1];   // anti
        res[lst][n - i - 1] = mat[i][lst];
    }
    for(int j = nw; j < n - nw; j++){
        // res[lst][j] = mat[j][n - lst - 1];   // anti
        res[j][n - lst - 1] = mat[lst][j];
    }
    for(int i = nw; i < n - nw; i++){
        // res[i][nw] = mat[nw][n - i - 1]; // anti
        res[nw][n - i - 1] = mat[i][nw];
    }
    
    // asigning values;
    for(int j = nw; j < n - nw; j++){
        mat[nw][j] = res[nw][j];
    }
    for(int i = nw; i < n - nw; i++){
        mat[i][lst] = res[i][lst];
    }
    for(int j = nw; j < n - nw; j++){
        mat[lst][j] = res[lst][j];
    }
    for(int i = nw; i < n - nw; i++){
        mat[i][nw] = res[i][nw];
    }
    return;
}