#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    
    while(n--){
        int x;
        cin>>x;
        int cnt=0;
        while(x){
            cnt+=x&1;
            x=x>>1;
        }
        cout<<cnt<<" ";
    }
    cout<<endl;
    return 0;
}
