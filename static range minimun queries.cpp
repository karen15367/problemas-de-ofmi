#include <iostream>
#include <vector>
#include <math.h>
 
using namespace std;
typedef long long int lli;
 
lli n,val_n,N,q,x,y;
vector<lli>arbol;
 
void inicializa(int n){
    int pot=log2(n);
    if(n!=pow(2,pot)){
        pot++;
    }
    N=pow(2,pot);
    arbol.resize(2*N,0);
}
 
void actualiza(int i,int dato){
    int j=N+i;
    arbol[j]=dato;
    j/=2;
    while(j>0){
        arbol[j]=min(arbol[j*2],arbol[j*2+1]);
        j/=2;
    }
}
 
int minimo(int a,int b){
    a+=N,b+=N;
    lli mini=(1e18);
    while(a<=b){
        if(a%2==1){
            mini=min(mini,arbol[a++]);
        }
        if(b%2==0){
            mini=min(mini,arbol[b--]);
        }
        a/=2,b/=2;
    }
    return mini;
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
    cin>>n>>q;
    inicializa(n);
    for(int i=1;i<=n;i++){
        cin>>val_n;
        actualiza(i,val_n);
    }
    while(q-->0){
        cin>>x>>y;
        cout<<minimo(x,y)<<"\n";
    }
 
    return 0;
}
