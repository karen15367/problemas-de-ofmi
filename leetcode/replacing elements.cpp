#include <iostream>
#include <algorithm>

using namespace std;

int n,d,arr[102],t;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  cin>>t;
  while(t-->0){
    cin>>n>>d;
    bool ok=true;
    for(int i=1;i<=n;i++){
      cin>>arr[i];
      if(arr[i]>d){
        ok=false;
      }
    }
    sort(arr+1,arr+1+n);
    if(arr[1]+arr[2]<=d || ok){
      cout<<"YES\n";
    }
    else{
      cout<<"NO\n";
    }
  }

  return 0;
}
