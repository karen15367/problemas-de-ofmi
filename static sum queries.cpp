#include <iostream>
 
using namespace std;
 
int n,q,a,b;
long long int arr[200002];
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]+=arr[i-1];
    }
    while(q-->0){
        cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<"\n";
    }
 
    return 0;
}
