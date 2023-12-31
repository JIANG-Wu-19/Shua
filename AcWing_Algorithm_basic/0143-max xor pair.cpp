#include<iostream>
#include<algorithm>

using namespace std;

const int N=1e6+10,M=31*N;

int n;
int a[N];
int son[M][2],idx;

void insert(int x){
    int p=0;
    for(int i=30;i>=0;i--){
        int u=x>>i&1;
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
}

int search(int x){
    int res=0;
    int p=0;
    for(int i=30;i>=0;i--){
        int u=x>>i&1;
        if(son[p][!u]){
            p=son[p][!u];
            res=res*2+1;
        }
        else{
            p=son[p][u];
            res=res*2;
        }
    }
    return res;
}

int main(){
    cin>>n;
    idx=0;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        insert(a[i]);
    }
    
    int res=0;
    
    for(int i=0;i<n;i++){
        res=max(res,search(a[i]));
    }
    cout<<res<<endl;
    return 0;
}
