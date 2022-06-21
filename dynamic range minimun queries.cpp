#include <iostream>
#include <vector>
#include <math.h>
 
using namespace std;
typedef long long int lli;
 
lli n,N,d,q,a,b;
vector<lli>arbol;
 
void inicializa(int n){
    lli pot=log2(n);
    if(n!=pow(2,pot)){
        pot++;
    }
    N=pow(2,pot);
    arbol.resize(2*N,0);
}
 
void actualiza(int i,int dato){
    int j=N+i;
    arbol[j]=d;
    j/=2;
    while(j>0){
        arbol[j]=min(arbol[j*2],arbol[j*2+1]);
        j/=2;
    }
}
 
lli minimo(int a,int b){
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
        cin>>d;
        actualiza(i,d);
    }
    while(q-->0){
        int id;
        cin>>id>>a>>b;
        if(id==1){
            actualiza(a,b);
        }
        else{
            cout<<minimo(a,b)<<"\n";
        }
    }
 
    return 0;
}
