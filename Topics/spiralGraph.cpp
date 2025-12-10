// https://codeforces.com/contest/2036/problem/D
for(int i = 0; i < k / 2; i++){
    vector<int> v;
    for(int j = i; j < m - i; j++){
        v.push_back(a[i][j]);
        // cout<<a[i][j]<<nl;
    }
    for(int j = i + 1; j < n - i; j++){
        v.push_back(a[j][m - 1 - i]);
        // cout<<SS<<a[j][m - 1 - i]<<nl;
    }
    for(int j = m - 1 - i - 1; j >= i; j--){
        v.push_back(a[n - 1 - i][j]);
        // cout<<SS<<SS<<a[n - 1 - i][j]<<nl;
    }
    for(int j = n - 1 - i - 1; j >= i + 1; j--){
        v.push_back(a[j][i]);
        // cout<<SS<<SS<<SS<<a[j][i]<<nl;
    }
}


// https://codeforces.com/contest/2102/problem/C

def magical_spiral(n):
    arr = [[-1] * n for _ in range(n)]
    
    if n % 2 == 0:
        x, y = n // 2 - 1, n // 2 - 1
    else:
        x, y = n // 2, n // 2
    
    arr[x][y] = 0
    value = step = 1

    dir = [(0, 1), (1, 0), (0, -1), (-1, 0)]


    while value < n * n:
        for d in range(4):
            steps = step
            
            step += d % 2; dx, dy = dir[d]

            for _ in range(steps):
                x += dx; y += dy

                if 0 <= x < n and 0 <= y < n and arr[x][y] == -1:
                    arr[x][y] = value
                    value += 1
                if value >= n * n:
                    break
            
            if value >= n * n:
                break


    for row in arr:
        print(" ".join(str(num) for num in row))
    print()


t = int(input())

for _ in range(t):
    n = int(input())

    magical_spiral(n)



// https://codeforces.com/contest/2102/problem/C
int n;cin>>n;
int val = 0;
int r = (n + 1) / 2, c = (n + 1) / 2;
int l1 = (n + 1) / 2, r1 = (n + 1) / 2, l2 = (n + 1) / 2, r2 = (n + 1) / 2;
int a[n + 1][n + 1];

a[r][c] = val++;

while(l1 >= 1 && l2 <= n){

    l2++;
    if(l2 > n)break;

    while(c < l2){
        c++;
        a[r][c] = val++;
    }
    while(r < l2){
        r++;
        a[r][c] = val++;
    }
    while(c > l1){
        c--;
        a[r][c] = val++;
    }




    l1--;

    if(l1 < 1)break;

    while(c > l1){
        c--;
        a[r][c] = val++;
    }
    while(r > l1){
        r--;
        a[r][c] = val++;
    }
    while(c < l2){
        c++;
        a[r][c] = val++;
    }
}

for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
        cout<<a[i][j]<<" ";
    }
    cout<<nl;
}