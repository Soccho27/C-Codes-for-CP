1. DSU
vector<int> rnk(sz);
vector<int> parent(sz);

int findUPar(int node){
    if(node==parent[node])return node;
    return parent[node]=findUPar(parent[node]);
}

void setRank(int u,int v){
	int UltParU=findUPar(u);
    int UltParV=findUPar(v);
    if(UltParU==UltParV)return;
    if(rnk[UltParU]>rnk[UltParV])parent[UltParV]=UltParU;
    else if(rnk[UltParU]<rnk[UltParV]) parent[UltParU]=UltParV;
    else {parent[UltParV]=UltParU;rnk[UltParU]++;}
}

bool isCycle(int u,int v){
    int UltParU=findUPar(u);
    int UltParV=findUPar(v);
    if(UltParU==UltParV)return true;
    return false;
}

rnk.assign(n+1,0);
iota(parent.begin(),parent.begin()+n+1,0);